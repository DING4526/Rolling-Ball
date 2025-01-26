#include "corewidget.h"

corewidget::corewidget(QWidget *parent)
    : QWidget{parent}
{}

void corewidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/mainbackground2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    painter.end();
}
