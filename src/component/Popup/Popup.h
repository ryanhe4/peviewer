//
// Created by yangheechan on 2021-05-16.
//

#ifndef PEVIEWER_POPUP_H
#define PEVIEWER_POPUP_H

#include <QWidget>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class Popup;
}
QT_END_NAMESPACE

class Popup : public QWidget {
    Q_OBJECT

public:
    explicit Popup(QWidget* parent = nullptr);
    ~Popup() override;

private:
    std::unique_ptr<Ui::Popup> ui;
};

#endif//PEVIEWER_POPUP_H
