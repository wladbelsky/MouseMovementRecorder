#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void mouseInfoUpdate(QMouseEvent event);

private slots:
    void on_settingButton_clicked();
    void timerTick();

private:
    Ui::MainWindow *ui;
    unsigned int interval = 5;
    unsigned int distance = 0;
    QPoint prev = QPoint(-1,-1), curr = QPoint(-1,-1);
    QTimer *timer;
    QString settingsPath;

    void updateDistance();
    void loadSettings();
    void saveSettings();

};
#endif // MAINWINDOW_H
