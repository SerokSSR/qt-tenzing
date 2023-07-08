#include "form.h"
#include "ui_form.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QPushButton>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}

void Form::on()
{

}
