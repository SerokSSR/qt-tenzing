#ifndef ROLE_H
#define ROLE_H

#include <QObject>
#include <QPoint>
#include <QImage>
#include "const.h"

const QString dialog[10][2] = {
    {"",""},
    {"你不幸碰触了传统香烟，生命值-5",""},
    {"你捡到了芋泥啵啵味烟弹，攻击力+10",""},
    {"然日卡在哪里？\n然日卡……然日卡……",""},
    {"远处的雪山……",""},
    };

class Role : public QObject
{
    Q_OBJECT
public:
    explicit Role(QObject *parent = nullptr);

    int mRow;
    int mCol;

    bool pick;

    QPoint mPaintPos;
    QImage mImg;

    void Move(int _dRow, int _dCol);
    void Paint(QPainter* _p, QPoint _pos);
    void PaintDialog(QPainter* _p, int _type);

signals:

};

#endif // ROLE_H
