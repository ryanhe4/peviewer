//
// Created by yangheechan on 2021-05-02.
//

#ifndef PEVIEWER_MAINWINDOW_H
#define PEVIEWER_MAINWINDOW_H
#include <QGraphicsEffect>
#include <QMainWindow>
#include <memory>

#include "../component/Popup/Popup.h"
#include "../component/Sidebar/sidebar.h"
#include "../component/SidebarItem/sidebaritem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
    bool eventFilter(QObject* obj, QEvent* event) override;

private:
    std::unique_ptr<Ui::MainWindow> m_ui;
    std::unique_ptr<Sidebar> m_side;
    std::unique_ptr<QGraphicsOpacityEffect> m_ScreenMaskEffect;
    std::unique_ptr<Popup> m_Popup;
public slots:
    void showPopup();
};

#endif //PEVIEWER_MAINWINDOW_H
