//
// Created by yangheechan on 2021-05-02.
//

#ifndef PEVIEWER_SIDEBAR_H
#define PEVIEWER_SIDEBAR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Sidebar; }
QT_END_NAMESPACE

class Sidebar : public QWidget {
Q_OBJECT

public:
    explicit Sidebar(QWidget* parent = nullptr);
    ~Sidebar() override;
private:
    Ui::Sidebar* ui;
};

#endif //PEVIEWER_SIDEBAR_H
