#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "qpainter.h"
#include "const.h"
#include <QObject>


class GameMap : public QObject
{
    Q_OBJECT
public:
    explicit GameMap(QObject *parent = nullptr);

    void InitByFile(QString fileName);

    void Paint(QPainter* _p, QPoint _Pos);

    void InitByRand();
    int mRow;
    int mCol;
    int mPArr[440][440];
    int curRow, curCol;

signals:

};

#endif // GAMEMAP_H
