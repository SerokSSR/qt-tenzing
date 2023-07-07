#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "mypushbutton.h"
#include "widget.h"
#include "widget1.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1800,1000);
    setWindowIcon(QIcon("://res/2.jpg"));
    setWindowTitle("理塘丁真的奇幻大冒险");

    //开始游戏
    startBtn = new MyPushButton("://res/start.png");
    startBtn->setParent(this);
    startBtn->move(50,this->height()*0.4);
    connect(startBtn,&MyPushButton::clicked,[=](){
        this->hide();
        Widget1 *a = new Widget1();
        a->show();
    });
    startBtn->setAttribute(Qt::WA_Hover, true);
    startBtn->installEventFilter(this);
    //退出游戏
    quitBtn = new MyPushButton("://res/quit.png");
    quitBtn->setParent(this);
    quitBtn->move(50,this->height()*0.6);
    quitBtn->setAttribute(Qt::WA_Hover, true);
    quitBtn->installEventFilter(this);
    connect( quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()) );
}
void  MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("://res/2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load("://res/3.png");
    painter.drawPixmap(100,0,pix);

}
MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if(obj==startBtn){
        if(event->type()== QEvent::HoverEnter) {
            QPixmap pix;
            bool flag = pix.load("://res/start2.png");
            if(!flag){
                qDebug()<<"图片加载失败";
            }
            startBtn->setFixedSize(pix.width(),pix.height());
            startBtn->setStyleSheet("QPushButton{border:0px;}");
            startBtn->setIcon(pix);
            startBtn->setIconSize(QSize(pix.width(),pix.height()));
            return true;
        }
        if(event->type()==QEvent::HoverLeave){
            QPixmap pix;
            bool flag = pix.load("://res/start.png");
            if(!flag){
                qDebug()<<"图片加载失败";
            }
            startBtn->setFixedSize(pix.width(),pix.height());
            startBtn->setStyleSheet("QPushButton{border:0px;}");
            startBtn->setIcon(pix);
            startBtn->setIconSize(QSize(pix.width(),pix.height()));
            return true;
        }
    }
    if(obj==quitBtn){
        if(event->type()== QEvent::HoverEnter) {
            QPixmap pix;
            bool flag = pix.load("://res/quit2.png");
            if(!flag){
                qDebug()<<"图片加载失败";
            }
            quitBtn->setFixedSize(pix.width(),pix.height());
            quitBtn->setStyleSheet("QPushButton{border:0px;}");
            quitBtn->setIcon(pix);
            quitBtn->setIconSize(QSize(pix.width(),pix.height()));
            return true;
        }
        if(event->type()==QEvent::HoverLeave){
            QPixmap pix;
            bool flag = pix.load("://res/quit.png");
            if(!flag){
                qDebug()<<"图片加载失败";
            }
            quitBtn->setFixedSize(pix.width(),pix.height());
            quitBtn->setStyleSheet("QPushButton{border:0px;}");
            quitBtn->setIcon(pix);
            quitBtn->setIconSize(QSize(pix.width(),pix.height()));
            return true;
        }
    }
    return QWidget::eventFilter(obj,event);
}
