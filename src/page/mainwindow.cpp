//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"

#include "../lib/UtilMgr.h"
#include <QLabel>
#include <QObject>
#include <memory>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), m_ui(new Ui::MainWindow),
      m_ScreenMaskEffect(new QGraphicsOpacityEffect),
      m_Popup(new Popup)
{
    m_ui->setupUi(this);

    setStyleSheet("MainWindow {background: white; width: 260px; height: 720;}");
    m_side = std::make_unique<Sidebar>(this);

    m_ui->horizontalLayout->addWidget(m_side.get());
    m_ui->horizontalLayout->setSpacing(32);

    // Temp MainPage, Ui 및 클래스로 분리예정
    auto* pv = new QLabel(this);
    pv->setMinimumWidth(968);
    pv->setText(QString("main page"));
    auto temp = UtilMgr::instance().getPalette(Color::teal)[500];
    QString style = QString("QLabel{ color: %1; font-size: 1.5rem; line-height: 1.5rem; background: red;"
                            "}"
                            "QLabel:hover {"
                            "color: %2"
                            "}")
                            .arg(temp)
                            .arg(UtilMgr::instance().getPalette(Color::teal)[700]);
    pv->setStyleSheet(style);
    m_ui->horizontalLayout->addWidget(pv);

    // Popup Dim 설정
    m_ScreenMaskEffect->setOpacity(1);
    m_ScreenMaskEffect->setOpacityMask(QColor(1, 1, 1));
    this->centralWidget()->setGraphicsEffect(m_ScreenMaskEffect.get());

    // Windows Icon 설정
    setWindowIcon(QIcon(":///lib/icon/workspace.svg"));

    setFixedWidth(1280);
    setFixedHeight(720);

    installEventFilter(this);
    connect(m_side->ExitItem(), &SidebarItem::onExit, this, &MainWindow::showPopup);
    connect(m_Popup.get(), &Popup::onExit, this, &MainWindow::close);
    connect(m_Popup.get(), &Popup::onHide, this,
            [this]() {
                m_ScreenMaskEffect->setOpacity(1);
                m_side->setEnabled(true);
            });
}
void MainWindow::showPopup()
{
    m_side->setEnabled(false);
    m_ScreenMaskEffect->setOpacity(0.7);

    m_Popup->move(rect().center());
    m_Popup->show();
}
bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() != QEvent::HoverMove)
        qDebug() << "[MainEvent] " << event->type();
    return QObject::eventFilter(obj, event);
}

MainWindow::~MainWindow() = default;
