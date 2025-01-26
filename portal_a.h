#ifndef PORTAL_A_H
#define PORTAL_A_H

#include <QWidget>
#include <QLabel>

class portal_a : public QLabel
{
    Q_OBJECT
public:
    explicit portal_a(QWidget *parent = nullptr);

    int x1,y1,x2,y2;
    int dir[2][4]={
        {1,0,-1,0},
        {0,1,0,-1}
    },d;

signals:
};

#endif // PORTAL_A_H
