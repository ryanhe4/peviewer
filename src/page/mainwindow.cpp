//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"

#include <QLabel>
#include <memory>
#include "../lib/UtilMgr.h"

MainWindow::MainWindow(QWidget* parent)
        :
        QMainWindow(parent), ui(new Ui::MainWindow)//, cw(new QWidget(centralWidget()))
{
    ui->setupUi(this);

    setStyleSheet("MainWindow {background: white; width: 260px; height: 720;}");

    m_side = std::make_unique<Sidebar>(this);

    ui->horizontalLayout->addWidget(m_side.get());
    ui->horizontalLayout->setSpacing(32);

    // Temp MainPage, Ui 및 클래스로 분리예정
    auto* pv = new QLabel(this);
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
    ui->horizontalLayout->addWidget(pv);

    // Windows Icon 설정
    //setWindowIcon(QIcon(":///lib/icon/workspace.svg"));

    setFixedWidth(1280);
    setFixedHeight(720);

    //connect(m_side.get(), &Sidebar::click, this, &MainWindow::close)
}

MainWindow::~MainWindow() = default;

