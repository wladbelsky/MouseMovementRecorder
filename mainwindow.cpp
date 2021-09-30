#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseInfoUpdate(QMouseEvent event)
{
    ui->mouseInfoLabel->setText(QString("%1:%2").arg(event.x()).arg(event.y()));
}


