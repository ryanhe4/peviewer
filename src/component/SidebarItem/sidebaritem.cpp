//
// Created by yangheechan on 2021-05-05.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SidebarItem.h" resolved

#include "sidebaritem.h"
#include "ui_SidebarItem.h"
#include "../../lib/UtilMgr.h"

SidebarItem::SidebarItem(QWidget* parent , QString _title ,QString _rccPath )
        :
        QWidget(parent), ui(new Ui::SidebarItem)
{
    ui->setupUi(this);
    ui->ItemText->setText(_title);

    ui->ItemText->setStyleSheet(QString(" QWidget {"
                                        "background: transparent; "
                                        "color: %1; "
                                        "}").arg(UtilMgr::instance().getPalette(Color::blueGrey)[600]));
}

SidebarItem::~SidebarItem()= default;

