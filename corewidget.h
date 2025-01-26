#ifndef COREWIDGET_H
#define COREWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

class corewidget : public QWidget
{
    Q_OBJECT
public:
    explicit corewidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);

    int x1,x2,y1,y2;

signals:
};

#endif // COREWIDGET_H
