#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "patterns.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //initial settings
    //that are sent into settingsform

    moveSettings.setSpeed(10);
    moveSettings.setSteps(250);
    moveSettings.setPattern(&Patterns::leftRight);

    settingsForm = new SettingsForm;
    aboutForm = new AboutForm;

    timer = new QTimer(this);
    timer_active = false;
    connect(timer,&QTimer::timeout, this, &MainWindow::run);

    connect(this,&MainWindow::sendSettings,settingsForm,&SettingsForm::receiveSettings);
    connect(settingsForm,&SettingsForm::sendSettings,this,&MainWindow::receiveSettings);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->label_2->setText("Active");
    ui->label_2->setStyleSheet("color: green");
    timer->start(moveSettings.getSpeed() * ONE_SEC);
    timer_active = true;
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_2->setText("Not Active");
    ui->label_2->setStyleSheet("color: black");
        if(!timer.isNull()){
            timer->stop();
            timer_active = false;
        }
}

void MainWindow::run(){
    moveSettings.runPattern();
}



void MainWindow::on_pushButton_3_clicked()
{
    emit sendSettings(moveSettings);
    settingsForm->show();
}

void MainWindow::closeEvent(QCloseEvent *event){
    QApplication::closeAllWindows();
}

void MainWindow::receiveSettings(MoveSettings s){
    this->moveSettings = s;
    if(timer_active){
    timer->start(moveSettings.getSpeed() * ONE_SEC);
    };
}

void MainWindow::on_pushButton_4_clicked()
{
    aboutForm->show();
}

