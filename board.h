#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QLabel>

class board : public QLabel
{
    Q_OBJECT
public:
    explicit board(QWidget *parent = nullptr);

    int x1,x2,y1,y2;

signals:
};

#endif // BOARD_H
