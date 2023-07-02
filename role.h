#ifndef ROLE_H
#define ROLE_H

#include <QObject>
#include <QPoint>
#include <QImage>

class Role : public QObject
{
    Q_OBJECT
public:
    explicit Role(QObject *parent = nullptr);

    int mRow;
    int mCol;

    QPoint mPaintPos;
    QImage mImg;

    void Move(int _dRow, int _dCol);
    void Paint(QPainter* _p, QPoint _pos);

signals:

};

#endif // ROLE_H
