#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(interval*1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseInfoUpdate(QMouseEvent event)
{
    ui->mouseInfoLabel->setText(QString("%1:%2").arg(event.x()).arg(event.y()));
    if(prev.x() == -1 && prev.y() == -1)
    {
        prev = QPoint(event.x(), event.y());
        curr = prev;
    }
    else
    {
        curr = QPoint(event.x(), event.y());
        auto dist = prev - curr;
        distance += dist.manhattanLength();
        prev = curr;
    }
    updateDistance();
}

void MainWindow::on_settingButton_clicked()
{
    SettingsDialog *dialog = new SettingsDialog(this);
    if(dialog->exec() == QDialog::Accepted)
    {
        interval = dialog->getIntervalSetting();
        timer->setInterval(interval*1000);
    }
}

void MainWindow::timerTick()
{
    distance = 0;
    updateDistance();
}

void MainWindow::updateDistance()
{
    ui->pathLabel->setText(QString("За последние %1 секунд пройдено %2 px").arg(interval).arg(distance));
}
