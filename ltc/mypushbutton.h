#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushBotton(QWidget *parent = nullptr);
    // 参数一 正常显示的图片路径    参数二 按下后现实的图片路径
    MyPushButton(QString normalImg, QString pressImg = "");

    QString normalImgPath;
    QString pressImgPath;

signals:

};

#endif // MYPUSHBUTTON_H
