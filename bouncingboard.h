#ifndef BOUNCINGBOARD_H
#define BOUNCINGBOARD_H

#include <QWidget>
#include <QLabel>

class bouncingboard : public QLabel
{
    Q_OBJECT
public:
    explicit bouncingboard(QWidget *parent = nullptr);

    int x1,x2,y1,y2;

signals:
};

#endif // BOUNCINGBOARD_H
