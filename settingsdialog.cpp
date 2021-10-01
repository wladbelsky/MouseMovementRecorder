#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(unsigned int interval,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    ui->secondsBox->setValue(interval);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

int SettingsDialog::getIntervalSetting()
{
    return ui->secondsBox->value();
}
