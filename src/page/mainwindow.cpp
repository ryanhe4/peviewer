//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"

#include <QLayout>
#include <QPushButton>
#include <QLabel>
MainWindow::MainWindow(QWidget* parent)
        :
        QMainWindow(parent), ui(new Ui::MainWindow), m_side(this), centralWidget(new QWidget(this))
{
    ui->setupUi(this);

    auto* layout = new QHBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    centralWidget->setLayout(layout);
    setStyleSheet("* {background: white;}");
    // sidebar size
    m_side.setStyleSheet("* {background: red;}");
    layout->addWidget(&m_side, 33);

    auto* pv = new QLabel(this);
    pv->setText(QString("main page"));
    layout->addWidget(pv, 66);

    setCentralWidget(centralWidget);
    setFixedWidth(1280);
    setFixedHeight(720);
}

MainWindow::~MainWindow() = default;

