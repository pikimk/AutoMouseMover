#ifndef ABOUTFORM_H
#define ABOUTFORM_H

#include <QWidget>
#include <QUrl>
#include <QDesktopServices>

namespace Ui {
class AboutForm;
}

class AboutForm : public QWidget
{
    Q_OBJECT

public:
    explicit AboutForm(QWidget *parent = nullptr);
    ~AboutForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AboutForm *ui;
};

#endif // ABOUTFORM_H
