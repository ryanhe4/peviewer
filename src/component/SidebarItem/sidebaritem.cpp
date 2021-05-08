//
// Created by yangheechan on 2021-05-05.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SidebarItem.h" resolved
#include <QDomDocument>
#include <QGraphicsSvgItem>
#include <QPainter>
#include <QSvgRenderer>
#include <QSvgWidget>

#include "../../lib/UtilMgr.h"
#include "sidebaritem.h"
#include "ui_SidebarItem.h"

void SetAttrRecur(QDomElement& elem, QString strtagname, QString strattr, QString strattrval)
{
    // if it has the tagname then overwritte desired attribute
    if (elem.tagName().compare(strtagname) == 0) {
        elem.setAttribute(strattr, strattrval);
    }
    // loop all children
    for (int i = 0; i < elem.childNodes().count(); i++) {
        if (!elem.childNodes().at(i).isElement()) {
            continue;
        }
        auto elem_ = elem.childNodes().at(i).toElement();
        SetAttrRecur(elem_, strtagname, strattr, strattrval);
    }
}

SidebarItem::SidebarItem(QWidget* parent, QString _title, QString _rccPath)
    : QWidget(parent), ui(new Ui::SidebarItem), isSelect(false)
{
    ui->setupUi(this);
    ui->ItemText->setText(_title);

    //isSelect 값에 따라 background Color 변경
    ui->wrapper->setStyleSheet(QString("QWidget#wrapper {"
                                       "background: %1;"
                                       "border-radius:8px;"
                                       "}"
                                       "QWidget#wrapper:hover{"
                                       "background: %2;"
                                       "}")
                                       .arg((!isSelect ? "white" : UtilMgr::instance().getPalette(Color::blueGrey)[50]),
                                            UtilMgr::instance().getPalette(Color::blueGrey)[50]));
    ui->ItemText->setStyleSheet(QString(" QWidget {"
                                        "color: %1; "
                                        "}")
                                        .arg(UtilMgr::instance().getPalette(Color::blueGrey)[600]));
}

SidebarItem::~SidebarItem() = default;
