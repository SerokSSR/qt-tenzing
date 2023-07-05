#include "widget.h"
#include "./ui_widget.h"
#include <QString>
#include <QMessageBox>
#include<QLabel>
#include<QFileDialog>
#include <cstdlib>
#include<windows.h>
#include<math.h>
#include<algorithm>
int Protect::pro[6]={1000,333,111,37,13,4};

void sleep_msec(int msec){
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
};
Widget::Widget(Widget1* w0,pokemon* p0,QWidget *parent)
    : QWidget(parent)
    , pk1(p0)
    , ui(new Ui::Widget)
    , w1(w0)
{
    pk2=new ironhands;
    ui->setupUi(this);
    ui->skl1->setAttribute(Qt::WA_Hover, true);
    ui->skl1->installEventFilter(this);
    ui->skl2->setAttribute(Qt::WA_Hover, true);
    ui->skl2->installEventFilter(this);
    ui->skl3->setAttribute(Qt::WA_Hover, true);
    ui->skl3->installEventFilter(this);
    ui->skl4->setAttribute(Qt::WA_Hover, true);
    ui->skl4->installEventFilter(this);//安装事件过滤器
    ui->hp1->setText(QString::number(pk1->get_hp_now(),10)+"/"+QString::number(pk1->get_hp(),10));
    ui->hp2->setText(QString::number(pk2->get_hp_now(),10)+"/"+QString::number(pk2->get_hp(),10));
    anime1=new QPropertyAnimation(ui->label,"geometry");
    anime1->setDuration(200);
    anime1->setStartValue(QRect{-10,230,351,251});
    anime1->setStartValue(QRect{90,230,351,251});
    anime1->setEasingCurve(QEasingCurve::Linear);
    anime2=new QPropertyAnimation(ui->label_3,"geometry");
    anime2->setDuration(200);
    anime2->setStartValue(QRect{520,-10,691,361});
    anime2->setStartValue(QRect{420,-10,691,361});
    anime2->setEasingCurve(QEasingCurve::Linear);
}
void Widget::slow_show(QString qstr){
    int time_sum=qstr.length();
    for(int i=1;i<=time_sum;i++){
        ui->msgbar->setText("    "+qstr.mid(0,i));
        sleep_msec(25);
    }
}
bool Widget::attack(pokemon* p1,pokemon* p2,skill& skl1,skill&skl2){
    if(skl1.get_name()=="守住"){
        int p=rand()%1000;
        if(p<=Protect::pro[p1->suc]) p1->suc++;
        else p1->suc=0;
    }
    else p1->suc=0;
    if(p1->get_name()=="古剑豹"){
        anime1->start();
    }
    else{
        anime2->start();
    }
    if(skl2.get_name()=="守住"&&p2->suc!=0){
        if(skl1.get_name()!="守住") slow_show("   "+p1->get_name()+"使用了"+skl1.get_name()+"但是被"+p2->get_name()+"防住了！");
        else slow_show("   "+p1->get_name()+"使用了"+skl1.get_name());
    }
    else{
        double damage=(210*p1->get_atk()*skl1.get_pow())/(250*p2->get_def());
        if(skl1.get_name()!="守住") damage+=2;
        p2->hp_now-=damage;
        if(skl1.get_name()=="疯狂伏特"){
            p1->hp_now-=damage/4;
        }
        if(skl1.get_name()=="守住"&&p1->suc==0) slow_show("   "+p1->get_name()+"使用了"+skl1.get_name()+"但是失败了！");
        else slow_show("   "+p1->get_name()+"使用了"+skl1.get_name());
    }
    skl1.use_pp();
    ui->hp1->setText(QString::number(pk1->get_hp_now(),10)+"/"+QString::number(pk1->get_hp(),10));
    ui->hp2->setText(QString::number(pk2->get_hp_now(),10)+"/"+QString::number(pk2->get_hp(),10));
    if(pk2->hp_now<=0){
        sleep_msec(1000);
        this->close();
        w1->show();
        return 0;
    }
    if(pk1->hp_now<=0){
        sleep_msec(1000);
        this->close();
        return 0;
    }
    return 1;
}

void Widget::battle(pokemon* p1,pokemon* p2,skill& skl1,skill& skl2){
    if(judge_prior(p1,p2,skl1,skl2)==0){
        battle(p2,p1,skl2,skl1);return;
    }
    ui->msgbar2->raise();
    ui->msgbar->raise();
    if(!attack(p1,p2,skl1,skl2)){
        sleep_msec(300);
        return;
    }
    sleep_msec(500);
    ui->msgbar->setText("");
    sleep_msec(500);
    if(skl1.get_name()=="冰柱坠击"){
        int r=rand()%100;
        if(r<30){
            ui->msgbar->setText("   "+p2->get_name()+"畏缩了！");
            sleep_msec(500);
            ui->msgbar->lower();
            ui->msgbar2->lower();
            return;
        }
    }
    attack(p2,p1,skl2,skl1);
    sleep_msec(500);
    ui->msgbar->lower();
    ui->msgbar2->lower();
}
//事件过滤器
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->skl1) {
        if(event->type() == QEvent::HoverEnter) {
            ui->pp1->setText(QString::number(pk1->get_pp(0),10));
            ui->pp2->setText(QString::number(pk1->get_pp_max(0),10));
            ui->type->setText(pk1->skl[0].get_type());
            return true;
        }
        if(event->type() == QEvent::HoverLeave){
            ui->pp1->setText("");
            ui->pp2->setText("");
            ui->type->setText("");
            return true;
        }
        if(event->type()==QEvent::MouseButtonPress){
            ui->pp1->setText(QString::number(pk1->get_pp(0)-1,10));
            battle(pk1,pk2,pk1->skl[0],pk2->skl[rand()%4]);
            return true;
        }
    }
    if(obj == ui->skl2) {
        if(event->type() == QEvent::HoverEnter) {
            ui->pp1->setText(QString::number(pk1->get_pp(1),10));
            ui->pp2->setText(QString::number(pk1->get_pp_max(1),10));
            ui->type->setText(pk1->skl[1].get_type());
            return true;
        }
        if(event->type() == QEvent::HoverLeave){
            ui->pp1->setText("");
            ui->pp2->setText("");
            ui->type->setText("");
            return true;
        }
        if(event->type()==QEvent::MouseButtonPress){
            ui->pp1->setText(QString::number(pk1->get_pp(1)-1,10));
            battle(pk1,pk2,pk1->skl[1],pk2->skl[rand()%4]);
            return true;
        }
    }
    if(obj == ui->skl3) {
        if(event->type() == QEvent::HoverEnter) {
            ui->pp1->setText(QString::number(pk1->get_pp(2),10));
            ui->pp2->setText(QString::number(pk2->get_pp_max(2),10));
            ui->type->setText(pk1->skl[2].get_type());
            return true;
        }
        if(event->type() == QEvent::HoverLeave){
            ui->pp1->setText("");
            ui->pp2->setText("");
            ui->type->setText("");
            return true;
        }
        if(event->type()==QEvent::MouseButtonPress){
            ui->pp1->setText(QString::number(pk1->get_pp(2)-1,10));
            battle(pk1,pk2,pk1->skl[2],pk2->skl[rand()%4]);
            return true;
        }
    }
    if(obj == ui->skl4) {
        if(event->type() == QEvent::HoverEnter) {
            ui->pp1->setText(QString::number(pk1->get_pp(3),10));
            ui->pp2->setText(QString::number(pk1->get_pp_max(3),10));
            ui->type->setText(pk1->skl[3].get_type());
            return true;
        }
        if(event->type() == QEvent::HoverLeave){
            ui->pp1->setText("");
            ui->pp2->setText("");
            ui->type->setText("");
            return true;
        }
        if(event->type()==QEvent::MouseButtonPress){
            ui->pp1->setText(QString::number(pk1->get_pp(3)-1,10));
            battle(pk1,pk2,pk1->skl[3],pk2->skl[rand()%4]);
            return true;
        }
    }
    return QWidget::eventFilter(obj,event);
}
Widget::~Widget()
{
    delete ui;
}

