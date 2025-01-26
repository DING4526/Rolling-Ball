#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <QPaintEvent>
#include <QSize>
#include <QMatrix4x4>
#include "ball.h"
#include "trap.h"
#include "destination.h"
#include "corewidget.h"
#include "board.h"
#include "bouncingboard.h"
#include "vortex.h"
#include "portal_a.h"
#include "portal_b.h"
#include "recorddot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent* ev);
    void paintEvent(QPaintEvent*);

    void victory();
    void defeat(ball*);
    void retry(ball*);

    void setrecord(recorddot*,int,int,int,int,int);
    void settrap(trap*,int,int,int,int);
    void setdest(destination*,int,int,int,int);
    void setwall(corewidget*,int,int,int,int);
    void setboard(board*,int,int,int,int);
    void setbouncingboard(bouncingboard*,int,int,int,int);
    void setvortex(vortex*,int,int,int,int,float);
    void setportal_a(portal_a*,int,int,int,int,int d);
    void setportal_b(portal_b*,int,int,int,int,int d);

    void adjustslider(ball*);
    void portal_transfer(ball*,portal_a*,portal_b*);
    void gotorecord(ball*,recorddot*);

    void checkrecord(ball* ball,recorddot* rec);
    void checktrap(ball* ball,trap* trap);
    void checkdest(ball* ball,destination* dest);
    void checkwall(ball* ball,corewidget* widget);
    void checkboard(ball* ball,board* board);
    void checkbouncingboard(ball* ball,bouncingboard* B_board);
    void checkvortex(ball* ball,vortex* vortex,QPixmap pix1,QPixmap pix2);
    void checkportal_a(ball* ball,portal_a* pa,portal_b* pb);

private:
    Ui::MainWindow *ui;

    int mode=1;
    int rec_mode=0;

    int mode3_flag1=0;
    int mode3_flag2=0;

    int width=1000;
    int height=750;

signals:
    void Press_A();
    void Press_D();
    void Press_S();
    void Press_W();

    void mode_choose1();
    void mode_choose2();
    void mode_choose3();

    void reach_destination();
    void reach_trap();
};
#endif // MAINWINDOW_H
