//
// Created by yangheechan on 2021-05-02.
//

#ifndef PEVIEWER_SIDEBAR_H
#define PEVIEWER_SIDEBAR_H

#include <QLayout>
#include <QMouseEvent>
#include <QWidget>
#include <memory>

#include "../SidebarItem/sidebaritem.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Sidebar;
}
QT_END_NAMESPACE

class Sidebar : public QWidget {
    Q_OBJECT

    std::unique_ptr<Ui::Sidebar> ui;
    std::unique_ptr<SidebarItem> m_homeItem;
    std::unique_ptr<SidebarItem> m_loadItem;
    std::unique_ptr<SidebarItem> m_exitItem;

public:
    explicit Sidebar(QWidget* parent = nullptr);
    ~Sidebar() override;
    bool eventFilter(QObject* watched, QEvent* event);

private:
    // method
    auto setUiStyle() -> void;
    auto setSidebarItem() -> void;
};

#endif//PEVIEWER_SIDEBAR_H
