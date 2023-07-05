#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include "gamemap.h"
#include "role.h"
#include "pokemon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget1; }
QT_END_NAMESPACE

class Widget1 : public QWidget
{
    Q_OBJECT

public:
    Widget1(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    void Collision(int _dRow, int _dCol);
    void DrawMap(int x, int y);
    ~Widget1();

private:
    Ui::Widget1 *ui;
    GameMap* mMap;
    QPainter* mMapPainter;
    Role* mRole;
    QTimer* mTimer;
    pokemon* pao;
    bool active; int actx, acty, actRole;
    bool pick; int pickType;

};
#endif // WIDGET_H
