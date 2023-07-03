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
    _p->drawImage(QRect(_Pos.x() + mCol*Size, _Pos.y() + mRow*Size, Size, Size), mImg);
}

void Role::PaintDialog(QPainter* _p, int _type) {
    _p->drawImage(QRect(20, 300,600, 500), QImage(":/image/dialog.png"));
    _p->setPen(QPen(Qt::black,10));
    _p->drawText(QRect(600, 100, 400, 200), Qt::AlignCenter, dialog[_type][0]);
}
