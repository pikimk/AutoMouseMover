#include "aboutform.h"
#include "ui_aboutform.h"

AboutForm::AboutForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutForm)
{
    ui->setupUi(this);
}

AboutForm::~AboutForm()
{
    delete ui;
}

void AboutForm::on_pushButton_clicked()
{
    this->close();
}


void AboutForm::on_pushButton_2_clicked()
{
    QUrl url("https://github.com/pikimk");
    QDesktopServices::openUrl(url);
}

