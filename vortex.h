#ifndef VORTEX_H
#define VORTEX_H

#include <QWidget>
#include <QLabel>
#include <QPaintEvent>

class vortex : public QLabel
{
    Q_OBJECT
public:
    explicit vortex(QWidget *parent = nullptr);

    int x1,x2,y1,y2;
    double v_min;
    bool issafe;

signals:
};

#endif // VORTEX_H
