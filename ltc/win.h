#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class win;
}

class win : public QWidget
{
    Q_OBJECT

public:
    explicit win(QWidget *parent = nullptr);
    ~win();
    void up();

private:
    Ui::win *ui;
};

#endif // WIN_H
