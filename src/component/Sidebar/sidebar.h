//
// Created by yangheechan on 2021-05-02.
//

#ifndef PEVIEWER_SIDEBAR_H
#define PEVIEWER_SIDEBAR_H

#include <QWidget>
#include <QLayout>
#include <memory>
QT_BEGIN_NAMESPACE
namespace Ui { class Sidebar; }
QT_END_NAMESPACE

class Sidebar : public QWidget {
Q_OBJECT
public:
    explicit Sidebar(QWidget* parent = nullptr);
    ~Sidebar() override;
private:
    std::unique_ptr<Ui::Sidebar> ui;
    auto setUiStyle() -> void;
};

#endif //PEVIEWER_SIDEBAR_H
