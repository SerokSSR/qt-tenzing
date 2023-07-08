#include "lose.h"
#include <QPainter>
#include "ui_lose.h"
#include <QPushButton>
#include "mainwindow.h"

lose::lose(QWidget *parent):
    QWidget(parent)
    ,ui(new Ui::lose)
{
    ui->setupUi(this);
    connect(ui->backBtn, SIGNAL(clicked()), qApp, SLOT(quit()) );
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->hide();
        MainWindow* a = new MainWindow();
        a->show();
    });
}

lose::~lose()
{
    delete ui;
}

