//
// Created by yangheechan on 2021-05-16.
//
#include "Popup.h"
#include "ui_Popup.h"

Popup::Popup(QWidget* parent) : QFrame(parent), m_UI(new Ui::Popup)
{
    m_UI->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);

    installEventFilter(this);
    connect(m_UI->pushButton, &QPushButton::clicked, this, [this]() {
        qDebug() <<"왼쪽클릭";
        emit onExit(); });
    connect(m_UI->pushButton_2, &QPushButton::clicked, this, [this]() { hide(); });
}

Popup::~Popup()
{
}
bool Popup::eventFilter(QObject* obj, QEvent* event)
{
    qDebug() << "[PopupEvent] " << event->type();
    if (event->type() == QEvent::Hide) {
        emit onHide();
    }
    return QObject::eventFilter(obj, event);
}
