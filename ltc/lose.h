#ifndef LOSE_H
#define LOSE_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class lose;
}

class lose : public QWidget
{
    Q_OBJECT

public:
    explicit lose(QWidget *parent = nullptr);
    ~lose();

private:
    Ui::lose *ui;
};

#endif // LOSE_H
