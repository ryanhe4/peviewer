//
// Created by yangheechan on 2021-05-02.
//
#include <QDirIterator>
#include "lib/UtilMgr.h"
#include "App.h"
int App::run() const
{
    UtilMgr::instance().log("Application is running");

    Q_INIT_RESOURCE(resource);
    QDirIterator it(":", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        qDebug() << it.next();
    }
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
