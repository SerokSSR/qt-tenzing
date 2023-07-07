#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include<widget.h>
#include <QPushButton>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void on();

private:
    Ui::Form *ui;
};

#endif // FORM_H
