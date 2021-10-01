#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(unsigned int interval, QWidget *parent = nullptr);
    ~SettingsDialog();
    int getIntervalSetting();

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
