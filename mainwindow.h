#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define ONE_SEC 1000

#include <QMainWindow>
#include <QTimer>
#include <QPointer>
#include <QThread>
#include "movesettings.h"
#include "settingsform.h"
#include "aboutform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

public slots:
    void run();
    void receiveSettings(MoveSettings s);
signals:
    void sendSettings(MoveSettings s);

private:

    void closeEvent(QCloseEvent *event);
    Ui::MainWindow *ui;
    bool timer_active;
    QPointer<QTimer> timer;
    QPointer<SettingsForm> settingsForm;
    QPointer <AboutForm> aboutForm;
    MoveSettings moveSettings;
};
#endif // MAINWINDOW_H
