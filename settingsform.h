#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QWidget>
#include "movesettings.h"

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsForm(QWidget *parent = nullptr);
    ~SettingsForm();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
public slots:
    void receiveSettings(MoveSettings s);
signals:
    void sendSettings(MoveSettings s);

private:
    MoveSettings moveSettings;
    Ui::SettingsForm *ui;
    QMap<QString,void(*)(int)> patternsMap;
    void initPatterns();
    void addPatterns();
};

#endif // SETTINGSFORM_H
