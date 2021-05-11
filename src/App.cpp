//
// Created by yangheechan on 2021-05-02.
//
#include <QDirIterator>
#include "App.h"
#include "lib/UtilMgr.h"

int App::run() const
{
    UtilMgr::instance().log("Application is running");

    UtilMgr::instance().log("Resource List start - ");
    QDirIterator it(":/lib", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        UtilMgr::instance().log( it.next().toUtf8().constData());
    }

    UtilMgr::instance().log("Resource List end - ");
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
