//
// Created by yangheechan on 2021-05-16.
//
#include "Popup.h"
#include "ui_Popup.h"

Popup::Popup(QWidget* parent) : QWidget(parent), ui(new Ui::Popup)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
}

Popup::~Popup()
{
}
