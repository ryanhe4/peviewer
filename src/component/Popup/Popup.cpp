//
// Created by yangheechan on 2021-05-16.
//
#include "Popup.h"
#include "ui_Popup.h"
#include <QGraphicsDropShadowEffect>

Popup::Popup(QWidget* parent) : QFrame(parent), m_UI(new Ui::Popup)
{
    m_UI->setupUi(this);
    setWindowModality(Qt::WindowModal);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    auto item = new QGraphicsDropShadowEffect;

    item->setOffset(0, 2);
    item->setBlurRadius(12);
    item->setColor(QColor::fromRgbF(0, 0, 0, 0.09));
    m_UI->widget->setGraphicsEffect(item);

    installEventFilter(this);
    connect(m_UI->pushButton, &QPushButton::clicked, this, [this]() { emit onExit(); });
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
