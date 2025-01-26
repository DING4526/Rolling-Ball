#ifndef PORTAL_B_H
#define PORTAL_B_H

#include <QWidget>
#include <QLabel>
#include "portal_a.h"

class portal_b : public QLabel
{
    Q_OBJECT
public:
    explicit portal_b(QWidget *parent = nullptr);

    int x1,y1,x2,y2;
    int dir[2][4]={
        {1,0,-1,0},
        {0,1,0,-1}
    },d;

signals:
};

#endif // PORTAL_B_H
