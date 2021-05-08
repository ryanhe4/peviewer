//
// Created by yangheechan on 2021-05-05.
//

#ifndef PEVIEWER_SIDEBARITEM_H
#define PEVIEWER_SIDEBARITEM_H

#include <QWidget>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class SidebarItem;
}
QT_END_NAMESPACE

class SidebarItem : public QWidget {
    Q_OBJECT
    std::unique_ptr<Ui::SidebarItem> ui;
    bool m_isSelect;
    bool m_SelectAble;
    QString m_title;

public:
    explicit SidebarItem(QWidget* parent = nullptr, QString _title = "Load",
                         bool _selectable = false,
                         bool _select = false,
                         QString _rccPath = ":/lib/icon/workspace.svg");
    ~SidebarItem() override;
    bool eventFilter(QObject* watched, QEvent* event);
};

#endif//PEVIEWER_SIDEBARITEM_H
