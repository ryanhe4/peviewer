//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Sidebar.h" resolved

#include "sidebar.h"
#include "ui_Sidebar.h"
#include <QLayout>

#include "../../lib/UtilMgr.h"
Sidebar::Sidebar(QWidget* parent)
    : QWidget(nullptr),
      ui(new Ui::Sidebar),
      m_homeItem(new SidebarItem(this, "Main", true, true)),
      m_loadItem(new SidebarItem(this, "Load")),
      m_exitItem(new SidebarItem(this, "Exit"))
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
    ui->Logo->setStyleSheet(QString("color: %1;")
                                    .arg(UtilMgr::instance().getPalette(Color::blueGrey)[800]));

    connect(m_exitItem.get(), &SidebarItem::onExit, this, &Sidebar::exit);
}
auto Sidebar::setSidebarItem() -> void
{
    //TODO Change items to Array and member variable?
    ui->sidebarItemLayout->addWidget(m_homeItem.get());
    ui->sidebarItemLayout->setAlignment(m_homeItem.get(), Qt::AlignTop);

    ui->sidebarItemLayout->addWidget(m_loadItem.get());
    ui->sidebarItemLayout->setAlignment(m_loadItem.get(), Qt::AlignTop);

    ui->sidebarItemLayout->addWidget(m_exitItem.get());
    ui->sidebarItemLayout->setStretch(2, 1);
    ui->sidebarItemLayout->setAlignment(m_exitItem.get(), Qt::AlignTop);
}

auto Sidebar::ExitItem() const -> SidebarItem*
{
    return m_exitItem.get();
}

Sidebar::~Sidebar() = default;
