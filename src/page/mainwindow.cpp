//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"

#include <QLayout>
#include <QLabel>
#include <memory>
#include "../lib/UtilMgr.h"

MainWindow::MainWindow(QWidget* parent)
        :
        QMainWindow(parent), ui(new Ui::MainWindow), cw(new QWidget(this))
{
    ui->setupUi(this);

    auto* layout = new QHBoxLayout();

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    //setStyleSheet("MainWindow {background: white; width: 260px; height: 720;}");
    setCentralWidget(cw);
    centralWidget()->setLayout(layout);

    m_side = std::make_unique<Sidebar>(this);

    m_side->show();

    layout->addWidget(m_side.get());
     auto* pv = new QLabel(this);
     pv->setText(QString("main page"));
     auto temp = UtilMgr::instance().getPalette(Color::teal)[500];
     QString style = QString("QLabel{ color: %1; font-size: 1.5rem; line-height: 1.5rem;"
                             "}"
                             "QLabel:hover {"
                             "color: %2"
                             "}").arg(temp)
             .arg(UtilMgr::instance().getPalette(Color::teal)[700]);
     pv->setStyleSheet(style);
     layout->addWidget(pv);
    setFixedWidth(1280);
    setFixedHeight(720);
}

MainWindow::~MainWindow() = default;

