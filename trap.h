#ifndef TRAP_H
#define TRAP_H

#include <QWidget>
#include <QLabel>
#include <QPaintEvent>

class trap : public QLabel
{
    Q_OBJECT
public:
    explicit trap(QWidget *parent = nullptr);

    int x1,x2,y1,y2;

signals:
};

#endif // TRAP_H
