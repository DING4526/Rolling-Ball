#ifndef RECORDDOT_H
#define RECORDDOT_H

#include <QWidget>
#include <QLabel>

class recorddot : public QLabel
{
    Q_OBJECT
public:
    explicit recorddot(QWidget *parent = nullptr);

    int x1,x2,y1,y2;
    int n;

signals:
};

#endif // RECORDDOT_H
