#ifndef BALL_H
#define BALL_H

#include "qwidget.h"
#include <QObject>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QDebug>

class ball : public QWidget
{
    Q_OBJECT
public:
    explicit ball(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);

    double ball_x=5;
    double ball_y=5;
    double ball_vx=0;
    double ball_vy=0;
    double ball_ax=0;
    double ball_ay=0;

    double rec_x=5,rec_y=5;
    int rec_n=0;

    void ballmove();

    void press_A();
    void press_D();
    void press_S();
    void press_W();

signals:


};

#endif // BALL_H
