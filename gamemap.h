#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "qpainter.h"
#include <QObject>

enum {
    Grass,
    Cigar,
    Elec,
    Jiu,
};

constexpr int Size = 20;
constexpr int N = 20;


class GameMap : public QObject
{
    Q_OBJECT
public:
    explicit GameMap(QObject *parent = nullptr);

    void InitByFile(QString fileName);

    void Paint(QPainter* _p, QPoint _Pos);

    void InitByRand();
    void PaintDialog(QPainter* _p, QPoint _Pos);

    int mRow;
    int mCol;
    int mPArr[440][440];

signals:

};

#endif // GAMEMAP_H
