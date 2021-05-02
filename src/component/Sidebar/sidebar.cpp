//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Sidebar.h" resolved

#include "sidebar.h"
#include "ui_Sidebar.h"

#include <QPushButton>
#include <QLayout>
Sidebar::Sidebar(QWidget* parent)
        :
        QWidget(parent), ui(new Ui::Sidebar)
{
    ui->setupUi(this);
    this->layout()->setContentsMargins(0, 0, 0, 0);
    layout()->setSpacing(0);
//    auto* p = new QPushButton("버튼",this);
//    p->setStyleSheet("QPushButton{border: 1px solid red;}");
//    qDebug() << geometry().;

//    QPushButton* pb = new QPushButton("버튼");
    auto* wz = new QWidget(this);
    this->layout()->addWidget(wz);
    setMaximumSize(260,720);
    setMinimumSize(260,720);
}

Sidebar::~Sidebar()
{
    delete ui;
}
QSize Sidebar::sizeHint() const
{
    return QSize(260,720);
}

