#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamemap.h"
#include "role.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    void Collision(int _dRow, int _dCol);
    void DrawMap(int x, int y);
    ~Widget();

private:
    Ui::Widget *ui;
    GameMap* mMap;
    QPainter* mMapPainter;
    Role* mRole;
    QTimer* mTimer;

    bool active; int actx, acty, actRole;
    bool pick; int pickType;

};
#endif // WIDGET_H
