#include "ball.h"
#include "corewidget.h"

ball::ball(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(parent->width(),parent->height());
}

void ball::paintEvent(QPaintEvent*)
{
    QPainter* painter=new QPainter(this);
    painter->setPen(QPen(Qt::black,1));
    painter->setBrush(QBrush(Qt::black));
    painter->drawEllipse(QPoint(ball_x,ball_y),5,5);
    painter->end();
}

void ball::press_A()
{
    if(ball_ax>-0.099)
    ball_ax-=0.005;
}
void ball::press_D()
{
    if(ball_ax<0.099)
    ball_ax+=0.005;
}
void ball::press_S()
{
    if(ball_ay<0.099)
    ball_ay+=0.005;
}
void ball::press_W()
{
    if(ball_ay>-0.099)
    ball_ay-=0.005;
}

void ball::ballmove()
{
    ball_vx+=ball_ax;
    ball_vy+=ball_ay;
    ball_x+=ball_vx;
    ball_y+=ball_vy;
}






















