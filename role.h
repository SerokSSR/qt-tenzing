#ifndef ROLE_H
#define ROLE_H

#include <QObject>
#include <QPoint>
#include <QImage>
#include "const.h"

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
