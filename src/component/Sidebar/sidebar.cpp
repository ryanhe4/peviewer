//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Sidebar.h" resolved

#include "sidebar.h"
#include "ui_Sidebar.h"

#include <QPushButton>
#include <QLayout>
#include "../../lib/UtilMgr.h"
Sidebar::Sidebar(QWidget* parent)
        :
        QWidget(nullptr), ui(new Ui::Sidebar)
{
    ui->setupUi(this);
    ui->Logo->setStyleSheet(QString("color: %1;").arg(UtilMgr::instance().getPalette(Color::blueGrey)[800]));

    setMaximumSize(260, 720);
    setMinimumSize(260, 720);
}

Sidebar::~Sidebar() = default;
