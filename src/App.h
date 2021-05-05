//
// Created by yangheechan on 2021-05-02.
//
#ifndef PEVIEWER_APP_H
#define PEVIEWER_APP_H

#include <QApplication>
#include <QPushButton>
#include <memory>

#include "page/mainwindow.h"
class App {
public:
    App(int argc, char* argv[]);
    ~App();

    int run() const;
    std::unique_ptr<QApplication> m_app;
    std::unique_ptr<MainWindow> m_main_window;
};

#endif //PEVIEWER_APP_H
