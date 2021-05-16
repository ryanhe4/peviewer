//
// Created by yangheechan on 2021-05-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"

#include "../component/Popup/Popup.h"
#include "../lib/UtilMgr.h"
#include <QGraphicsEffect>
#include <QLabel>
#include <QPainter>
#include <memory>

class DarkenEffect : public QGraphicsEffect {
public:
    void draw(QPainter* painter) override
    {
        QPixmap pixmap;
        QPoint offset;
        if (sourceIsPixmap())// No point in drawing in device coordinates (pixmap will be scaled anyways)
            pixmap = sourcePixmap(Qt::LogicalCoordinates, &offset);
        else// Draw pixmap in device coordinates to avoid pixmap scaling;
        {
            pixmap = sourcePixmap(Qt::DeviceCoordinates, &offset);
            painter->setWorldTransform(QTransform());
        }
        painter->setBrush(QColor(0, 0, 0, 255));// black bg
        painter->drawRect(pixmap.rect());
        painter->setOpacity(0.7);
        painter->drawPixmap(offset, pixmap);
    }
};

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setStyleSheet("MainWindow {background: white; width: 260px; height: 720;}");
    m_side = std::make_unique<Sidebar>(this);

    ui->horizontalLayout->addWidget(m_side.get());
    ui->horizontalLayout->setSpacing(32);

    // Temp MainPage, Ui 및 클래스로 분리예정
    auto* pv = new QLabel(this);
    pv->setMinimumWidth(968);
    pv->setText(QString("main page"));
    auto temp = UtilMgr::instance().getPalette(Color::teal)[500];
    QString style = QString("QLabel{ color: %1; font-size: 1.5rem; line-height: 1.5rem; background: red;"
                            "}"
                            "QLabel:hover {"
                            "color: %2"
                            "}")
                            .arg(temp)
                            .arg(UtilMgr::instance().getPalette(Color::teal)[700]);
    pv->setStyleSheet(style);
    ui->horizontalLayout->addWidget(pv);

    // Windows Icon 설정
    setWindowIcon(QIcon(":///lib/icon/workspace.svg"));

    setFixedWidth(1280);
    setFixedHeight(720);

    connect(m_side->ExitItem(), &SidebarItem::onExit, this, &MainWindow::showPopup);
}
void MainWindow::showPopup()
{
    //m_side->setEnabled(false);
    auto popup = new Popup(this);
    popup->move(rect().center());
    popup->show();

    this->setGraphicsEffect(new DarkenEffect);
}

MainWindow::~MainWindow() = default;

