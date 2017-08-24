#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stoneshell.h"

#include <QPainter>
#include <QDebug>
#include <QResizeEvent>
#include <QWebChannel>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlWebChannel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_NoSystemBackground, false);
    setAttribute(Qt::WA_TranslucentBackground);

    ui->quickWidget->setClearColor(Qt::transparent);

    move(0, 0);

    StoneShell *stoneShell = new StoneShell();

    m_mainChannel = new QQmlWebChannel();
    m_mainChannel->registerObject("StoneShell", stoneShell);

    ui->quickWidget->engine()->rootContext()->setContextProperty("mainChannel", m_mainChannel);
    ui->quickWidget->engine()->rootContext()->setContextProperty("StoneShell", stoneShell);
    ui->quickWidget->setSource(QUrl("qrc:/qml/main.qml"));
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    setMask(QRegion(0, 0, event->size().width(), event->size().height()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_mousePressPos = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    #ifdef Q_OS_MAC
    const QPoint delta = event->globalPos() - m_mousePressPos;
    move(x() + delta.x(), y() + delta.y());
    m_mousePressPos = event->globalPos();
    #else
    move(x(), y());
    #endif
}



MainWindow::~MainWindow()
{
    delete ui;
}
