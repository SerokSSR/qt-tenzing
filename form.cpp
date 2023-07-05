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
    setFixedSize(520,400);
    //父类为当前类的窗口this
    QLabel *lb = new QLabel(this);
    QImage im;
    //图片路径可以通过右击工程的图片获取
    im.load(":/res/lose2.jpg");
    lb->setPixmap(QPixmap::fromImage(im));
    //设置lable相对于父类的位置
    lb->setGeometry(im.rect());
    lb->show();

    MyPushButton * startBtn = new MyPushButton(":/res/lose1.png");
    startBtn->setParent(this);
    startBtn->move(80,this->height()*0.3);
    QPushButton * backBtn = new QPushButton("返回游戏");
    backBtn->setParent(this);
    backBtn->move(180,this->height()*0.6);
    QFont font("楷体",20,10,0);
    backBtn->setFont(font);
    connect( backBtn, SIGNAL(clicked()), qApp, SLOT(quit()) );
}

Form::~Form()
{
    delete ui;
}

void Form::on()
{

}
