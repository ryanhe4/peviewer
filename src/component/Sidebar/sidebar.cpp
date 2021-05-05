//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Sidebar.h" resolved

#include "sidebar.h"
#include "ui_Sidebar.h"

#include <QLayout>
#include "../SidebarItem/sidebaritem.h"
#include "../../lib/UtilMgr.h"
Sidebar::Sidebar(QWidget* parent)
        :
        QWidget(nullptr), ui(new Ui::Sidebar)
{
    ui->setupUi(this);

    setSidebarItem();
    setUiStyle();
    // set ClickEvent
    setMaximumSize(260, 720);
    setMinimumSize(260, 720);
}
auto Sidebar::setUiStyle() -> void
{
    // Logo Style
    ui->Logo->setStyleSheet(QString("color: %1;").arg(UtilMgr::instance().getPalette(Color::blueGrey)[800]));
}
auto Sidebar::setSidebarItem() -> void
{
    //TODO Change items to Array and member variable
    auto* item = new SidebarItem(nullptr);
    ui->sidebarItemLayout->addWidget(item);
    ui->sidebarItemLayout->setStretch(1,1);
    ui->sidebarItemLayout->setAlignment(item, Qt::AlignTop);

    auto* item2 = new SidebarItem(nullptr, "Exit");
    ui->sidebarItemLayout->addWidget(item2);
    ui->sidebarItemLayout->setStretch(1,1);
    ui->sidebarItemLayout->setAlignment(item2, Qt::AlignTop);
}

Sidebar::~Sidebar() = default;
