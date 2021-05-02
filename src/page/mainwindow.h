//
// Created by yangheechan on 2021-05-02.
//

#ifndef PEVIEWER_MAINWINDOW_H
#define PEVIEWER_MAINWINDOW_H

#include <QMainWindow>
#include <memory>

#include "../component/Sidebar/sidebar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<Sidebar> m_side;
    QWidget* cw;
};

#endif //PEVIEWER_MAINWINDOW_H
