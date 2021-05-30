//
// Created by yangheechan on 2021-05-16.
//

#ifndef PEVIEWER_POPUP_H
#define PEVIEWER_POPUP_H

#include <QFrame>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class Popup;
}
QT_END_NAMESPACE

class Popup : public QFrame {
    Q_OBJECT

public:
    explicit Popup(QWidget* parent = nullptr);
    ~Popup() override;

    bool eventFilter(QObject* obj, QEvent* event) override;

private:
    std::unique_ptr<Ui::Popup> m_UI;
signals:
    void onExit();
    void onHide();
};

#endif//PEVIEWER_POPUP_H
