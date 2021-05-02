//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Sidebar.h" resolved

#include "sidebar.h"
#include "ui_Sidebar.h"

#include <QPushButton>
Sidebar::Sidebar(QWidget* parent)
        :
        QWidget(parent), ui(new Ui::Sidebar)
{
    ui->setupUi(this);

    auto* p = new QPushButton("버튼",this);
    ui->pushButton->setStyleSheet("QPushButton{background: black;}");
    p->setStyleSheet("QPushButton{border: 1px solid red;}");
}

Sidebar::~Sidebar()
{
    delete ui;
}

