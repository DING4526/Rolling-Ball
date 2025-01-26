#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class helpwidget;
}

class helpwidget : public QDialog
{
    Q_OBJECT

public:
    explicit helpwidget(QWidget *parent = nullptr);
    ~helpwidget();

private:
    Ui::helpwidget *ui;

signals:
    void mode1();
    void mode2();
    void mode3();
};

#endif // HELPWIDGET_H
