#pragma once


#include "qdatetime.h"
#include "ui_widget.h"
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include<QPropertyAnimation.h>
#include "widget1.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    friend pokemon;
    pokemon* pk1;
    pokemon* pk2;
    Widget(Widget1* w0,pokemon* p0,QWidget *parent = nullptr);
    bool attack(pokemon*p1,pokemon*p2,skill& skl1,skill& skl2);
    void battle(pokemon*p1,pokemon*p2,skill& skl1,skill& skl2);
    void slow_show(QString qstr);
    ~Widget();
    bool eventFilter(QObject *obj, QEvent *event);
    QPropertyAnimation * anime1;
    QPropertyAnimation * anime2;

public:
    QLabel* m_picLable;
private:
    Ui::Widget *ui;
    Widget1* w1;
};
#endif // WIDGET_H
