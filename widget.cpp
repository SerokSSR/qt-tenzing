#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    mMap = new GameMap(this);
    mMapPainter = new QPainter(this);

    mRole = new Role(this);
    mTimer = new QTimer(this);
    mTimer->start(100);

    // 定时调用更新函数
    connect(mTimer, &QTimer::timeout, [this]() {this->update(); });
    setFixedSize(1024, 500);
    
    active = false;
    this->update();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent* event) {
    mMapPainter->begin(this);

    //mMapPainter->drawImage(QRect(0, 0, 1050, 490), QImage("://image/background.png"));

    mMap->Paint(mMapPainter, QPoint(0, 0));
    
    mRole->Paint(mMapPainter, QPoint(0, 0));

    if(active) mMap->PaintDialog(mMapPainter, QPoint(20, 700));

    mMapPainter->end();
    QPainter painter(this);
    painter.setPen(QPen(Qt::red,3));
    painter.drawText(QRect(acty*20, (actx+1)*20, 20, 70), Qt::AlignCenter, "黄河之水天上来\n奔流到海不复回");
}

void Widget::keyPressEvent(QKeyEvent* event) {
    printf("keypressevent happened\n");
    active = false;
    switch(event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up: {
        //逻辑碰撞检测函数
        Collision(-1, 0);
        break;
    }
    case Qt::Key_S:
    case Qt::Key_Down: {
        //逻辑碰撞检测函数
        Collision(1, 0);
        break;
    }
    case Qt::Key_A:
    case Qt::Key_Left: {
        //逻辑碰撞检测函数
        Collision(0, -1);
        break;
    }
    case Qt::Key_D:
    case Qt::Key_Right: {
        //逻辑碰撞检测函数
        Collision(0, 1);
        break;
    }

    case Qt::Key_E: {
        // 显示交互
        active = true;
        actx = mRole->mRow; acty = mRole->mCol;
        break;
    }
    }
}

void Widget::Collision(int _dRow, int _dCol) {
    int newRow = mRole->mRow + _dRow;
    int newCol = mRole->mCol + _dCol;
//    if(newRow < 0 or newRow >= 20 or newCol < 0 or newCol >= 20) return ;
//    if(mPMap->mPArr[newRow][newCol] == 1) {
//        return;
//    }
    //else move
    mRole->Move(_dRow, _dCol);
}
