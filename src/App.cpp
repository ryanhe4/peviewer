//
// Created by yangheechan on 2021-05-02.
//
#include "lib/UtilMgr.h"
#include "App.h"
int App::run()
{
    UtilMgr::instance().log("Application is running");

    // show mainwindows items
    m_main_window->show();
    return m_app->exec();
}
App::~App() = default;
App::App(int argc, char** argv)
        :m_app(new QApplication(argc, argv)),
         m_main_window(new MainWindow)
{
    UtilMgr::instance().log("Application is created!");
}
