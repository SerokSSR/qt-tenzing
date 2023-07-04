#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

Widget1::Widget1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget1)
{
    ui->setupUi(this);
    
    mMap = new GameMap(this);
    mMapPainter = new QPainter(this);

    mRole = new Role(this);
    mTimer = new QTimer(this);
    mTimer->start(100);

    qDebug() << "Qt version:" << qVersion();
    // 定时调用更新函数
    connect(mTimer, &QTimer::timeout, [this]() {this->update(); });
    setFixedSize(900, 800);
    
    active = false;
    pick = false;
    this->update();
}

Widget1::~Widget1()
{
    delete ui;
}


void Widget1::paintEvent(QPaintEvent* event) {
    mMapPainter->begin(this);

    mMapPainter->setOpacity(0.2);
    mMapPainter->drawImage(QRect(0, 0, 1200, 850), QImage(":/image/snows.jpg"));
    mMapPainter->setOpacity(1);
    mMapPainter->drawImage(QRect(0, 0, 900, 800), QImage("://image/border.png"));


    //设置主窗口背景颜色
//    QPainter painter(this);

//    QColor color(246,240,235);
//    painter.setBrush(color);
//    painter.drawRect(this->rect());

    mMap->Paint(mMapPainter, QPoint(50, 50));
    
    mRole->Paint(mMapPainter, QPoint(50, 50));

    if(active) {
        mRole->PaintDialog(mMapPainter, mMap->mPArr[mRole->mRow][mRole->mCol]);
    }
    if(pick) {
        mRole->PaintDialog(mMapPainter, pickType);
    }
    mMapPainter->end();
}

void Widget1::keyPressEvent(QKeyEvent* event) {
    printf("keypressevent happened\n");
    pick = false;
    active = false;
    switch(event->key()) {
    case Qt::Key_Space: {
        // 进入战斗系统
        break;
    }
    case Qt::Key_Escape: {
        // 退出对话
        active = false;
        break;
    }
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
        //setOpacity(0.4);
        active = not active;
        actx = mRole->mRow; acty = mRole->mCol;
        break;
    }
    }
}

void Widget1::Collision(int _dRow, int _dCol) {
    int newRow = mRole->mRow + _dRow;
    int newCol = mRole->mCol + _dCol;
    if(newRow < 0 or newRow >= N or newCol < 0 or newCol >= N) return ;
//    if(mPMap->mPArr[newRow][newCol] == 1) {
//        return;
//    }
    //else move
    mRole->Move(_dRow, _dCol);
    if(mMap->mPArr[mRole->mRow][mRole->mCol] > 0 and mMap->mPArr[mRole->mRow][mRole->mCol] < 3) {
        pick = true;
        pickType = mMap->mPArr[mRole->mRow][mRole->mCol];
        mMap->mPArr[mRole->mRow][mRole->mCol] = 0;
    }

}
