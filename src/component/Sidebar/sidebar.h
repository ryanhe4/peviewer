//
// Created by yangheechan on 2021-05-02.
//

#ifndef PEVIEWER_SIDEBAR_H
#define PEVIEWER_SIDEBAR_H

#include <QLayout>
#include <QWidget>
#include <memory>
QT_BEGIN_NAMESPACE
namespace Ui {
class Sidebar;
}
QT_END_NAMESPACE

class Sidebar : public QWidget {
    Q_OBJECT
public:
    explicit Sidebar(QWidget* parent = nullptr);
    ~Sidebar() override;

private:
    //
    std::unique_ptr<Ui::Sidebar> ui;

private:
    // method
    auto setUiStyle() -> void;
    auto setSidebarItem() -> void;
};

#endif//PEVIEWER_SIDEBAR_H
