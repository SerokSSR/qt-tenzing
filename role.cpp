#include "role.h"
#include <QPainter>
#include <QDebug>

Role::Role(QObject *parent)
    : QObject{parent}
{
    mRow = 0;
    mCol = 0;
    mImg = QImage(":/image/chien-pao.png");

    //mPaintPos = QPoint(mCol, mRow) * mImg.width();

}

void Role::Move(int _dRow, int _dCol) {
    mRow += _dRow;
    mCol += _dCol;

    //mPaintPos = QPoint(mCol, mRow) * mImg.width();
}

void Role::Paint(QPainter* _p, QPoint _Pos) {
    //qDebug() << "role::paint at" << _Pos.x() + mCol*Size << ' ' << _Pos.y() + mRow*Size << Qt::endl;
    _p->setPen(QPen(Qt::darkRed, 2, Qt::DashLine));

    _p->drawImage(QRect(_Pos.x() + mCol*Size, _Pos.y() + mRow*Size, Size, Size), mImg);
    _p->drawArc(QRect(_Pos.x() + mCol*Size, _Pos.y() + mRow*Size, Size, Size), 0, 360*16);
    _p->setPen(QPen(Qt::black));
}

void Role::PaintDialog(QPainter* _p, int _type) {
    _p->drawImage(QRect(220, 280, 800, 600), QImage(":/image/dialog.png"));
    //_p->setPen(QPen(Qt::black, 50));
    //_p->drawText(QRect(345, 540, 400, 200), Qt::AlignCenter, "丁真");
    _p->setFont(QFont("思源宋体", 16));
    _p->drawText(QRect(345, 600, 400, 200), Qt::AlignCenter, dialog[_type][0]);
    if(_type!=3) _p->drawText(QRect(345, 650, 400, 200), Qt::AlignCenter, "（按空格跳过）");
    else _p->drawText(QRect(345, 650, 400, 200), Qt::AlignCenter, "（按空格进入战斗）");
}
