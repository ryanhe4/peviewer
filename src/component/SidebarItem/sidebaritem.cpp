//
// Created by yangheechan on 2021-05-05.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SidebarItem.h" resolved
#include <QMouseEvent>

#include "../../lib/UtilMgr.h"
#include "sidebaritem.h"
#include "ui_SidebarItem.h"

SidebarItem::SidebarItem(QWidget* parent, QString _title,
                         bool _selectable, bool _select,
                         const QString& _rccPath)
    : QWidget(parent), ui(new Ui::SidebarItem),
      m_isSelect(_select),
      m_SelectAble(_selectable),
      m_title(_title)
{
    ui->setupUi(this);
    ui->ItemText->setText(_title);

    setUiStyle();

    setProperty(_title.toUtf8().constData(), _title);
    installEventFilter(this);
}
bool SidebarItem::eventFilter(QObject* watched, QEvent* event)
{
    switch (event->type()) {
    case QMouseEvent::MouseButtonPress: {
        UtilMgr::instance().log(watched->property(m_title.toUtf8().constData()).toString().toUtf8().constData());
        UtilMgr::instance().log("OnMousePress(), ");
    } break;
    case QMouseEvent::MouseButtonRelease: {
        std::string str(watched->property(m_title.toUtf8().constData()).toString().toUtf8().constData());
        UtilMgr::instance().log(str);
        UtilMgr::instance().log("OnMouseRelease(), ");
        if (str == "Exit") {
            UtilMgr::instance().log("SidebarItem: onExit");
            emit onExit();
        }
    } break;
    default:
        break;
    }

    return QObject::eventFilter(watched, event);
}
auto SidebarItem::setUiStyle() -> void
{
    //m_isSelect state에 따라 background Color 변경
    ui->wrapper->setStyleSheet(QString("QWidget#wrapper {"
                                       "background: %1;"
                                       "border-radius:8px;"
                                       "}"
                                       "QWidget#wrapper:hover{"
                                       "background: %2;"
                                       "}")
                                       .arg((!m_isSelect ? "white" : UtilMgr::instance().getPalette(Color::blueGrey)[50]),
                                            UtilMgr::instance().getPalette(Color::blueGrey)[50]));
    ui->ItemText->setStyleSheet(QString(" QWidget {"
                                        "color: %1;"
                                        "%2"
                                        "}")
                                        .arg(UtilMgr::instance().getPalette(Color::blueGrey)[600], m_isSelect ? "font-weight: bold;" : ""));
}

SidebarItem::~SidebarItem() = default;
