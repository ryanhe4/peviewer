//
// Created by yangheechan on 2021-05-05.
//

#ifndef PEVIEWER_SIDEBARITEM_H
#define PEVIEWER_SIDEBARITEM_H

#include <QWidget>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class SidebarItem; }
QT_END_NAMESPACE

class SidebarItem : public QWidget {
Q_OBJECT

public:
    explicit SidebarItem(QWidget* parent = nullptr, QString _title = "Load",QString _rccPath = ":/lib/icon/workspace.svg");
    ~SidebarItem() override;

private:
    std::unique_ptr<Ui::SidebarItem> ui;
};

#endif //PEVIEWER_SIDEBARITEM_H
