#include "win.h"
#include "ui_win.h"
#include <QPainter>
#include "widget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include "./ui_win.h"

win::win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
    connect(ui->backBtn, SIGNAL(clicked()), qApp, SLOT(quit()) );
}

win::~win()
{
    delete ui;
}

void win::up()
{

}
