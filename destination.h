#ifndef DESTINATION_H
#define DESTINATION_H

#include <QWidget>
#include <QLabel>

class destination : public QLabel
{
    Q_OBJECT
public:
    explicit destination(QWidget *parent = nullptr);

    int x1,x2,y1,y2;

signals:

};

#endif // DESTINATION_H
