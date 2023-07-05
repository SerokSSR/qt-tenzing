#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mypushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *obj, QEvent *event);
    void paintEvent(QPaintEvent *);
    MyPushButton * startBtn;
    MyPushButton * quitBtn;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
