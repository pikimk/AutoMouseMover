#include "settingsform.h"
#include "ui_settingsform.h"
#include "patterns.h"

SettingsForm::SettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsForm)
{

    ui->setupUi(this);
    addPatterns();
    initPatterns();
}

SettingsForm::~SettingsForm()
{
    delete ui;
}

void SettingsForm::on_pushButton_2_clicked()
{
    this->close();
}

void SettingsForm::receiveSettings(MoveSettings s){
    moveSettings = s;
    ui->horizontalSlider->setValue(s.getSpeed());
    ui->horizontalSlider_2->setValue(s.getSteps());
    void(*pat_ptr)(int) = (void(*)(int))s.getPattern();
    int index = ui->comboBox->findText(patternsMap.key(pat_ptr));
    ui->comboBox->setCurrentIndex(index);
}

void SettingsForm::initPatterns(){

    QMap<QString,void(*)(int)>::Iterator it;

    for(it = patternsMap.begin(); it != patternsMap.end(); it++){
         ui->comboBox->addItem(it.key());
    }
}

void SettingsForm::on_pushButton_clicked()
{
    moveSettings.setSpeed(ui->horizontalSlider->value());
    moveSettings.setSteps(ui->horizontalSlider_2->value());
    moveSettings.setPattern(patternsMap.value(ui->comboBox->currentText()));
    emit sendSettings(moveSettings);
    this->close();
}

void SettingsForm::addPatterns(){
    //Add pattern into map here
    patternsMap.insert("Square",&Patterns::square);
    patternsMap.insert("Left Right", &Patterns::leftRight);
    patternsMap.insert("Circle",&Patterns::circle);
}

