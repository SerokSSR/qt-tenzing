#include "role.h"
#include <QPainter>

Role::Role(QObject *parent)
    : QObject{parent}
{
    mRow = 0;
    mCol = 0;
    mImg = QImage(":/image/ironbundle.png");

    //mPaintPos = QPoint(mCol, mRow) * mImg.width();

}

void Role::Move(int _dRow, int _dCol) {
    mRow += _dRow;
    mCol += _dCol;

    //mPaintPos = QPoint(mCol, mRow) * mImg.width();
}

void Role::Paint(QPainter* _p, QPoint _Pos) {
    printf("role::paint happened\n");
    _p->drawImage(QRect(_Pos.x() + mCol*20, _Pos.y() + mRow*20, 20, 20), mImg);
}
