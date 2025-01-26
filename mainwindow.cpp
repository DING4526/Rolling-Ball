#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include "destination.h"
#include "trap.h"
#include "helpwidget.h"

QTimer* maintimer =new QTimer();
QTimer* balltimer =new QTimer();


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap Vpix1,Vpix2;
    Vpix1.load(":/vortex_safe.png");
    Vpix2.load(":/vortex_danger.png");

    //小球和各物件的放置
    ball* aball=new ball(ui->widget);
    //qDebug()<<aball->width()<<aball->height();
    //aball->setFixedSize(ui->widget->x2-ui->widget->x1,ui->widget->y2-ui->widget->y1);
    setrecord(ui->rec1,ui->rec1->x(),ui->rec1->y(),ui->rec1->width(),ui->rec1->height(),1);
    setrecord(ui->rec2,ui->rec2->x(),ui->rec2->y(),ui->rec2->width(),ui->rec2->height(),2);
    setrecord(ui->rec3,ui->rec3->x(),ui->rec3->y(),ui->rec3->width(),ui->rec3->height(),3);
    setrecord(ui->rec4,ui->rec4->x(),ui->rec4->y(),ui->rec4->width(),ui->rec4->height(),4);
    setrecord(ui->rec5,ui->rec5->x(),ui->rec5->y(),ui->rec5->width(),ui->rec5->height(),5);//存档点
    setdest(ui->dest,ui->dest->x(),ui->dest->y(),ui->dest->width(),ui->dest->height());//终点
    settrap(ui->trap1,ui->trap1->x(),ui->trap1->y(),ui->trap1->width(),ui->trap1->height());
    settrap(ui->trap2,ui->trap2->x(),ui->trap2->y(),ui->trap2->width(),ui->trap2->height());
    settrap(ui->trap3,ui->trap3->x(),ui->trap3->y(),ui->trap3->width(),ui->trap3->height());
    settrap(ui->trap4,ui->trap4->x(),ui->trap4->y(),ui->trap4->width(),ui->trap4->height());
    settrap(ui->trap5,ui->trap5->x(),ui->trap5->y(),ui->trap5->width(),ui->trap5->height());
    settrap(ui->trap6,ui->trap6->x(),ui->trap6->y(),ui->trap6->width(),ui->trap6->height());
    settrap(ui->trap7,ui->trap7->x(),ui->trap7->y(),ui->trap7->width(),ui->trap7->height());
    settrap(ui->trap8,ui->trap8->x(),ui->trap8->y(),ui->trap8->width(),ui->trap8->height());
    settrap(ui->trap9,ui->trap9->x(),ui->trap9->y(),ui->trap9->width(),ui->trap9->height());
    settrap(ui->trap10,ui->trap10->x(),ui->trap10->y(),ui->trap10->width(),ui->trap10->height());
    settrap(ui->trap11,ui->trap11->x(),ui->trap11->y(),ui->trap11->width(),ui->trap11->height());
    settrap(ui->trap12,ui->trap12->x(),ui->trap12->y(),ui->trap12->width(),ui->trap12->height());
    //settrap(ui->label,ui->label->x(),ui->label->y(),ui->label->width(),ui->label->height());//陷阱
    setboard(ui->board1,ui->board1->x(),ui->board1->y(),ui->board1->width(),ui->board1->height());
    setboard(ui->board2,ui->board2->x(),ui->board2->y(),ui->board2->width(),ui->board2->height());
    setboard(ui->board3,ui->board3->x(),ui->board3->y(),ui->board3->width(),ui->board3->height());
    setboard(ui->board4,ui->board4->x(),ui->board4->y(),ui->board4->width(),ui->board4->height());
    setboard(ui->board5,ui->board5->x(),ui->board5->y(),ui->board5->width(),ui->board5->height());//挡板
    setbouncingboard(ui->B_board1,ui->B_board1->x(),ui->B_board1->y(),ui->B_board1->width(),ui->B_board1->height());
    setbouncingboard(ui->B_board2,ui->B_board2->x(),ui->B_board2->y(),ui->B_board2->width(),ui->B_board2->height());
    setbouncingboard(ui->B_board3,ui->B_board3->x(),ui->B_board3->y(),ui->B_board3->width(),ui->B_board3->height());
    setbouncingboard(ui->B_board4,ui->B_board4->x(),ui->B_board4->y(),ui->B_board4->width(),ui->B_board4->height());
    setbouncingboard(ui->B_board5,ui->B_board5->x(),ui->B_board5->y(),ui->B_board5->width(),ui->B_board5->height());
    setbouncingboard(ui->B_board6,ui->B_board6->x(),ui->B_board6->y(),ui->B_board6->width(),ui->B_board6->height());
    setbouncingboard(ui->B_board7,ui->B_board7->x(),ui->B_board7->y(),ui->B_board7->width(),ui->B_board7->height());
    setbouncingboard(ui->B_board8,ui->B_board8->x(),ui->B_board8->y(),ui->B_board8->width(),ui->B_board8->height());//弹板
    setvortex(ui->vortex1,ui->vortex1->x(),ui->vortex1->y(),ui->vortex1->width(),ui->vortex1->height(),0.6);
    setvortex(ui->vortex2,ui->vortex2->x(),ui->vortex2->y(),ui->vortex2->width(),ui->vortex2->height(),1.2);
    setvortex(ui->vortex3,ui->vortex3->x(),ui->vortex3->y(),ui->vortex3->width(),ui->vortex3->height(),1.4);
    setvortex(ui->vortex4,ui->vortex4->x(),ui->vortex4->y(),ui->vortex4->width(),ui->vortex4->height(),1.6);
    setvortex(ui->vortex5,ui->vortex5->x(),ui->vortex5->y(),ui->vortex5->width(),ui->vortex5->height(),1.5);
    setvortex(ui->vortex6,ui->vortex6->x(),ui->vortex6->y(),ui->vortex6->width(),ui->vortex6->height(),1.8);
    setvortex(ui->vortex7,ui->vortex7->x(),ui->vortex7->y(),ui->vortex7->width(),ui->vortex7->height(),1.8);
    setvortex(ui->vortex8,ui->vortex8->x(),ui->vortex8->y(),ui->vortex8->width(),ui->vortex8->height(),1.8);
    setvortex(ui->vortex9,ui->vortex9->x(),ui->vortex9->y(),ui->vortex9->width(),ui->vortex9->height(),1.2);//漩涡
    setportal_a(ui->portal_a1,ui->portal_a1->x(),ui->portal_a1->y(),ui->portal_a1->width(),ui->portal_a1->height(),2);//0右，1下，2左，3上
    setportal_a(ui->portal_a2,ui->portal_a2->x(),ui->portal_a2->y(),ui->portal_a2->width(),ui->portal_a2->height(),3);
    setportal_a(ui->portal_a3,ui->portal_a3->x(),ui->portal_a3->y(),ui->portal_a3->width(),ui->portal_a3->height(),2);
    setportal_a(ui->portal_a4,ui->portal_a4->x(),ui->portal_a4->y(),ui->portal_a4->width(),ui->portal_a4->height(),1);
    setportal_a(ui->portal_a5,ui->portal_a5->x(),ui->portal_a5->y(),ui->portal_a5->width(),ui->portal_a5->height(),3);
    setportal_a(ui->portal_a6,ui->portal_a6->x(),ui->portal_a6->y(),ui->portal_a6->width(),ui->portal_a6->height(),1);
    setportal_a(ui->portal_a7,ui->portal_a7->x(),ui->portal_a7->y(),ui->portal_a7->width(),ui->portal_a7->height(),0);
    setportal_b(ui->portal_b1,ui->portal_b1->x(),ui->portal_b1->y(),ui->portal_b1->width(),ui->portal_b1->height(),3);
    setportal_b(ui->portal_b3,ui->portal_b3->x(),ui->portal_b3->y(),ui->portal_b3->width(),ui->portal_b3->height(),1);
    setportal_b(ui->portal_b4,ui->portal_b4->x(),ui->portal_b4->y(),ui->portal_b4->width(),ui->portal_b4->height(),3);
    setportal_b(ui->portal_b5,ui->portal_b5->x(),ui->portal_b5->y(),ui->portal_b5->width(),ui->portal_b5->height(),1);
    setportal_b(ui->portal_b6,ui->portal_b6->x(),ui->portal_b6->y(),ui->portal_b6->width(),ui->portal_b6->height(),0);//传送门
    //qDebug()<<ui->dest->x1<<ui->dest->x2<<ui->dest->y1<<ui->dest->y2;

    ui->mode3_flag->close();
    ui->mode3_flag->setText("0/5次");

    //帮助窗口
    helpwidget* myhelpwidget=new helpwidget();

    //模式选择
    connect(myhelpwidget,&helpwidget::mode1,[=](){
        this->mode=1;
    });
    connect(myhelpwidget,&helpwidget::mode2,[=](){
        this->mode=2;
        ui->menu_2->setTitle("双人模式");
    });
    connect(myhelpwidget,&helpwidget::mode3,[=](){
        this->mode=3;
        ui->menu_2->setTitle("友尽模式");
        ui->mode3_flag->show();
    });

    myhelpwidget->exec();

    //窗口基础设置
    setFixedSize(width,height);
    setWindowTitle("Rolling Ball");
    setWindowIcon(QIcon(":/ball.png"));
    if(rec_mode==0)ui->menu_3->setTitle("普通版");
    //qDebug()<<ui->menuBar->height()<<ui->widget->height();
    setwall(ui->widget,ui->widget->x(),ui->widget->y()+ui->menuBar->height()-3,ui->widget->width()+ui->widget->x(),ui->widget->y()+ui->widget->height()+ui->menuBar->height()-3);
    connect(ui->actionquit,&QAction::triggered,[=](){this->close();});//菜单-退出
    connect(ui->actionpause,&QAction::triggered,[=](){
        maintimer->stop(),balltimer->stop();
        QDialog* pausewidget=new QDialog();
        pausewidget->setWindowTitle("游戏已暂停");
        pausewidget->setFixedSize(400,300);
        pausewidget->setWindowIcon(QIcon(":/pause.png"));
        pausewidget->setFont(QFont("华文仿宋",14,QFont::Bold));
        QLabel* back=new QLabel(pausewidget);
        QSize picSize(pausewidget->width(),pausewidget->height());
        QPixmap pix;
        pix.load(":/pause_back.png");
        pix=pix.scaled(picSize);
        back->setPixmap(pix);
        back->setStyleSheet("background:transparent");
        back->setAttribute(Qt::WA_TranslucentBackground);
        QPushButton* continuebtn=new QPushButton(pausewidget);
        QPushButton* retrybtn=new QPushButton(pausewidget);
        continuebtn->setText("继续游戏");
        continuebtn->setFixedSize(120,40);
        continuebtn->move(70,220);
        if(rec_mode==1)
            retrybtn->setText("返回存档点");
        else
            retrybtn->setText("重新开始");
        retrybtn->setFixedSize(120,40);
        retrybtn->move(210,220);
        connect(continuebtn,&QPushButton::clicked,[=](){
            pausewidget->close();
            maintimer->start(20),balltimer->start(20);
        });
        connect(retrybtn,&QPushButton::clicked,[=](){
            pausewidget->close();
            retry(aball);
        });
        pausewidget->exec();
        delete pausewidget;
    });//菜单-暂停
    connect(ui->actionhelp,&QAction::triggered,[=](){myhelpwidget->exec();});//菜单-帮助
    connect(ui->actionretry,&QAction::triggered,[=](){retry(aball);});//菜单-帮助
    connect(ui->helpButton,&QPushButton::clicked,[=](){ui->actionhelp->trigger();});//按钮-帮助
    connect(ui->quitButton,&QPushButton::clicked,[=](){ui->actionquit->trigger();});//按钮-退出
    connect(ui->pauseButton,&QPushButton::clicked,[=](){ui->actionpause->trigger();});//按钮-暂停
    connect(ui->actionmode1,&QAction::triggered,[=](){this->mode=1;ui->menu_2->setTitle("单人模式");ui->mode3_flag->close();});
    connect(ui->actionmode2,&QAction::triggered,[=](){this->mode=2;ui->menu_2->setTitle("双人模式");ui->mode3_flag->close();});
    connect(ui->actionmode3,&QAction::triggered,[=](){this->mode=3;ui->menu_2->setTitle("友尽模式");ui->mode3_flag->show();});//菜单-模式重选
    connect(ui->actionrecord1,&QAction::triggered,[=](){gotorecord(aball,ui->rec1);});
    connect(ui->actionrecord2,&QAction::triggered,[=](){gotorecord(aball,ui->rec2);});
    connect(ui->actionrecord3,&QAction::triggered,[=](){gotorecord(aball,ui->rec3);});
    connect(ui->actionrecord4,&QAction::triggered,[=](){gotorecord(aball,ui->rec4);});
    connect(ui->actionrecord5,&QAction::triggered,[=](){gotorecord(aball,ui->rec5);});//菜单-破解版存档点
    connect(ui->actioncracked_version,&QAction::triggered,[=](){
        ui->menu_3->setTitle("破解版");
        retry(aball);
        rec_mode=1;
    });
    connect(ui->actionnorm_version,&QAction::triggered,[=](){
        ui->menu_3->setTitle("普通版");
        rec_mode=0;
        retry(aball);
        QPixmap nullpix;
        nullpix.load("");
        aball->rec_n=0;
        ui->rec1->setPixmap(nullpix);
        ui->rec2->setPixmap(nullpix);
        ui->rec3->setPixmap(nullpix);
        ui->rec4->setPixmap(nullpix);
        ui->rec5->setPixmap(nullpix);
        ui->rec1->setText("R1");
        ui->rec2->setText("R2");
        ui->rec3->setText("R3");
        ui->rec4->setText("R4");
        ui->rec5->setText("R5");
    });//菜单-破解版模式选择

    //游戏获胜/失败判定
    connect(this,&MainWindow::reach_trap,[=](){
        defeat(aball);
    });
    connect(this,&MainWindow::reach_destination,[=](){
        victory();
    });


    //定时器设置
    maintimer->start(20);
    balltimer->start(20);
    connect(maintimer,&QTimer::timeout,[=](){
        update();
    });
    connect(balltimer,&QTimer::timeout,[=](){
        //每一帧计算小球运动
        aball->ballmove();
        //调整滑动条
        adjustslider(aball);
        //模式属性设置
        if(mode==3){
            QString str = QString("%1/5次").arg(std::max(this->mode3_flag1,mode3_flag2));
            ui->mode3_flag->setText(str);
            if(mode3_flag1>5||mode3_flag2>5){
                defeat(aball);
                mode3_flag1=mode3_flag2=0;
            }
        }
        if(rec_mode==1){
            checkrecord(aball,ui->rec1);
            checkrecord(aball,ui->rec2);
            checkrecord(aball,ui->rec3);
            checkrecord(aball,ui->rec4);
            checkrecord(aball,ui->rec5);
        }
        //每一帧检查碰壁情况
        checkwall(aball,ui->widget);
        //每一帧检查小球与物件相互作用情况
        checkdest(aball,ui->dest); //终点
        checktrap(aball,ui->trap1);
        checktrap(aball,ui->trap2);
        checktrap(aball,ui->trap3);
        checktrap(aball,ui->trap4);
        checktrap(aball,ui->trap5);
        checktrap(aball,ui->trap6);
        checktrap(aball,ui->trap7);
        checktrap(aball,ui->trap8);
        checktrap(aball,ui->trap9);
        checktrap(aball,ui->trap10);
        checktrap(aball,ui->trap11);
        checktrap(aball,ui->trap12);
        //checktrap(aball,ui->label);//陷阱
        checkboard(aball,ui->board1);
        checkboard(aball,ui->board2);
        checkboard(aball,ui->board3);
        checkboard(aball,ui->board4);
        checkboard(aball,ui->board5);//挡板
        checkbouncingboard(aball,ui->B_board1);
        checkbouncingboard(aball,ui->B_board2);
        checkbouncingboard(aball,ui->B_board3);
        checkbouncingboard(aball,ui->B_board4);
        checkbouncingboard(aball,ui->B_board5);
        checkbouncingboard(aball,ui->B_board6);
        checkbouncingboard(aball,ui->B_board7);
        checkbouncingboard(aball,ui->B_board8);//弹板
        checkvortex(aball,ui->vortex1,Vpix1,Vpix2);
        checkvortex(aball,ui->vortex2,Vpix1,Vpix2);
        checkvortex(aball,ui->vortex3,Vpix1,Vpix2);
        checkvortex(aball,ui->vortex4,Vpix1,Vpix2);
        checkvortex(aball,ui->vortex5,Vpix1,Vpix2);
        checkvortex(aball,ui->vortex6,Vpix1,Vpix2);
        checkvortex(aball,ui->vortex7,Vpix1,Vpix2);
        checkvortex(aball,ui->vortex8,Vpix1,Vpix2);
        checkvortex(aball,ui->vortex9,Vpix1,Vpix2);//漩涡
        checkportal_a(aball,ui->portal_a1,ui->portal_b1);
        checkportal_a(aball,ui->portal_a2,ui->portal_b1);
        checkportal_a(aball,ui->portal_a3,ui->portal_b3);
        checkportal_a(aball,ui->portal_a4,ui->portal_b4);
        checkportal_a(aball,ui->portal_a5,ui->portal_b5);
        checkportal_a(aball,ui->portal_a6,ui->portal_b6);
        checkportal_a(aball,ui->portal_a7,ui->portal_b3);//传送门
    });

    //键盘响应
    qDebug()<<"mode"<<mode;
    connect(this,&MainWindow::Press_A,aball,[=](){
        aball->press_A();
    });
    connect(this,&MainWindow::Press_D,aball,[=](){
        aball->press_D();
    });
    connect(this,&MainWindow::Press_S,aball,[=](){
        aball->press_S();
    });
    connect(this,&MainWindow::Press_W,aball,[=](){
        aball->press_W();
    });
}

void MainWindow::victory()
{
    qDebug()<<"victory";
    balltimer->stop(),maintimer->stop();
    QDialog* victory=new QDialog();
    victory->setFixedSize(400,250);
    victory->setWindowTitle("恭喜你，成功啦");
    victory->setWindowIcon(QIcon(":/victory.png"));
    victory->setFont(QFont("华文仿宋",14,QFont::Bold));
    QLabel* back=new QLabel(victory);
    QSize picSize(victory->width(),victory->height());
    QPixmap pix;
    pix.load(":/victory_back.png");
    pix=pix.scaled(picSize);
    back->setPixmap(pix);
    back->setStyleSheet("background:transparent");
    back->setAttribute(Qt::WA_TranslucentBackground);
    QPushButton* closebtn=new QPushButton(victory);
    closebtn->setFixedSize(100,40);
    closebtn->setText("退出");
    closebtn->move(150,180);
    connect(closebtn,&QPushButton::clicked,[=](){
        victory->close();
        this->close();
    });
    victory->exec();
    delete victory;
}
void MainWindow::defeat(ball* ball)
{
    qDebug()<<"defeat";
    balltimer->stop(),maintimer->stop();
    QDialog* defeat=new QDialog();
    defeat->setFixedSize(400,300);
    defeat->setFont(QFont("华文仿宋",14,QFont::Bold));
    defeat->setWindowTitle("失败了，别灰心，再试一次吧");
    defeat->setWindowIcon(QIcon(":/defeat.png"));
    QLabel* back=new QLabel(defeat);
    QSize picSize(defeat->width(),defeat->height());
    QPixmap pix;
    pix.load(":/defeat_back.png");
    pix=pix.scaled(picSize);
    back->setPixmap(pix);
    back->setStyleSheet("background:transparent");
    back->setAttribute(Qt::WA_TranslucentBackground);
    QPushButton* closebtn=new QPushButton(defeat);
    if(rec_mode==0){
        closebtn->setFixedSize(100,40);
        closebtn->setText("重试");
        closebtn->move(150,220);
    }
    else{
        closebtn->setFixedSize(120,40);
        closebtn->setText("返回存档点");
        closebtn->move(140,220);
    }
    connect(closebtn,&QPushButton::clicked,[=](){
        defeat->close();
        retry(ball);
    });
    defeat->exec();
    delete defeat;
}
void MainWindow::retry(ball* ball)
{
    if(rec_mode==1){
        ball->ball_x=ball->rec_x,ball->ball_y=ball->rec_y;
    }
    else{
        ball->ball_x=5,ball->ball_y=5;
        ball->rec_n=0,ball->rec_x=ball->rec_y=5;
    }
    ball->ball_ax=ball->ball_ay=ball->ball_vx=ball->ball_vy=0;
    balltimer->start(20),maintimer->start(20);
}

void MainWindow::portal_transfer(ball* ball,portal_a* pa,portal_b* pb)
{
    double vn=pa->dir[0][pa->d]*ball->ball_vx+pa->dir[1][pa->d]*ball->ball_vy;
    double vt=pa->dir[0][(pa->d+1)%4]*ball->ball_vx+pa->dir[1][(pa->d+1)%4]*ball->ball_vy;
    //qDebug()<<vn<<vt;
    ball->ball_x=(pb->x1+pb->x2)/2;
    ball->ball_y=(pb->y1+pb->y2)/2;
    ball->ball_vx=vn*pb->dir[0][pb->d]+vt*pb->dir[0][(pb->d+1)%4];
    //qDebug()<<vn<<"*"<<pb->dir[0][pb->d]<<"+"<<vt<<"*"<<pb->dir[0][(pb->d+1)%4];
    ball->ball_vy=vn*pb->dir[1][pb->d]+vt*pb->dir[1][(pb->d+1)%4];
    //qDebug()<<vn<<"*"<<pb->dir[1][pb->d]<<"+"<<vt<<"*"<<pb->dir[1][(pb->d+1)%4];
    //qDebug()<<ball->ball_vx<<ball->ball_vy;
}

void MainWindow::setrecord(recorddot* rec,int x,int y,int wid,int hei,int n)
{
    rec->x1=x;
    rec->x2=x+wid;
    rec->y1=y;
    rec->y2=y+hei;
    rec->n=n;
}
void MainWindow::settrap(trap* trap,int x,int y,int wid,int hei)
{
    trap->x1=x;
    trap->x2=x+wid;
    trap->y1=y;
    trap->y2=y+hei;
    QPixmap pix;
    QSize picSize(trap->x2-trap->x1,trap->y2-trap->y1);
    pix.load(":/trap.png");
    pix=pix.scaled(picSize);
    trap->setPixmap(pix);
}
void MainWindow::setdest(destination* dest,int x,int y,int wid,int hei)
{
    dest->x1=x;
    dest->x2=x+wid;
    dest->y1=y;
    dest->y2=y+hei;
    QPixmap pix;
    QSize picSize(dest->x2-dest->x1,dest->y2-dest->y1);
    pix.load(":/flag.png");
    pix=pix.scaled(picSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    dest->setPixmap(pix);
}
void MainWindow::setwall(corewidget* wall,int x1,int y1,int x2,int y2)
{
    wall->x1=x1;
    wall->x2=x2;
    wall->y1=y1;
    wall->y2=y2;
    qDebug()<<wall->x1<<wall->y1<<wall->x2<<wall->y2;
}
void MainWindow::setboard(board* board,int x,int y,int wid,int hei)
{
    board->x1=x;
    board->x2=x+wid;
    board->y1=y;
    board->y2=y+hei;
    QPixmap pix;
    QSize picSize(board->x2-board->x1,board->y2-board->y1);
    pix.load(":/board.png");
    pix=pix.scaled(picSize);
    board->setPixmap(pix);
}
void MainWindow::setbouncingboard(bouncingboard* B_board,int x,int y,int wid,int hei)
{
    B_board->x1=x;
    B_board->x2=x+wid;
    B_board->y1=y;
    B_board->y2=y+hei;
    QPixmap pix;
    QSize picSize(B_board->x2-B_board->x1,B_board->y2-B_board->y1);
    pix.load(":/bouncingboard.png");
    pix=pix.scaled(picSize);
    B_board->setPixmap(pix);
}
void MainWindow::setvortex(vortex* vortex,int x,int y,int wid,int hei,float vm)
{
    vortex->x1=x;
    vortex->x2=x+wid;
    vortex->y1=y;
    vortex->y2=y+hei;
    vortex->v_min=vm;
}
void MainWindow::setportal_a(portal_a* pa,int x,int y,int wid,int hei,int d)
{
    pa->x1=x;
    pa->x2=x+wid;
    pa->y1=y;
    pa->y2=y+hei;
    pa->d=d;
    QPixmap pix;
    QSize picSize(pa->x2-pa->x1,pa->y2-pa->y1);
    if(d==0)pix.load(":/inportal0.png");
    else if(d==1)pix.load(":/inportal1.png");
    else if(d==2)pix.load(":/inportal2.png");
    else if(d==3)pix.load(":/inportal3.png");
    pix=pix.scaled(picSize);
    pa->setPixmap(pix);
}
void MainWindow::setportal_b(portal_b* pb,int x,int y,int wid,int hei,int d)
{
    pb->x1=x;
    pb->x2=x+wid;
    pb->y1=y;
    pb->y2=y+hei;
    pb->d=d;
    QPixmap pix;
    QSize picSize(pb->x2-pb->x1,pb->y2-pb->y1);
    if(d==0)pix.load(":/outportal0.png");
    else if(d==1)pix.load(":/outportal1.png");
    else if(d==2)pix.load(":/outportal2.png");
    else if(d==3)pix.load(":/outportal3.png");
    pix=pix.scaled(picSize);
    pb->setPixmap(pix);
}

void MainWindow::adjustslider(ball* ball)
{
    ui->Slider_x->setValue(ball->ball_ax*300);
    ui->Slider_y->setValue(ball->ball_ay*300);
    ui->label_slider_x->setText(QString::number(ui->Slider_x->value())+"°");
    ui->label_slider_y->setText(QString::number(ui->Slider_y->value())+"°");
}
void MainWindow::gotorecord(ball* ball,recorddot* rec)
{
    ball->ball_ax=ball->ball_ay=ball->ball_vx=ball->ball_vy=0;
    ball->ball_x=(rec->x1+rec->x2)/2;
    ball->ball_y=(rec->y1+rec->y2)/2;
}

void MainWindow::checkrecord(ball* ball,recorddot* rec)
{
    if(ball->ball_x>rec->x1&&ball->ball_x<rec->x2&&ball->ball_y>rec->y1&&ball->ball_y<rec->y2&&rec->n>ball->rec_n){
        ball->rec_n=rec->n;
        ball->rec_x=(rec->x1+rec->x2)/2;
        ball->rec_y=(rec->y1+rec->y2)/2;
        QPixmap pix;
        QSize picSize(rec->x2-rec->x1,rec->y2-rec->y1);
        pix.load(":/rec_green.png");
        pix=pix.scaled(picSize);
        rec->setPixmap(pix);
        //rec->setText("已存档");
    }
}
void MainWindow::checktrap(ball* ball,trap* trap)
{
    if(ball->ball_x>trap->x1&&ball->ball_x<trap->x2&&ball->ball_y>trap->y1&&ball->ball_y<trap->y2){
        emit reach_trap();
    }
}
void MainWindow::checkdest(ball* ball,destination* dest)
{
    if(ball->ball_x>dest->x1&&ball->ball_x<dest->x2&&ball->ball_y>dest->y1&&ball->ball_y<dest->y2){
        victory();
    }
}
void MainWindow::checkwall(ball* ball,corewidget* widget)
{
    if(ball->ball_x<5){
        ball->ball_vx=0;
        ball->ball_x=5;
    }
    else if(ball->ball_x>widget->width()-5){
        ball->ball_vx=0;
        ball->ball_x=widget->width()-5;
    }
    if(ball->ball_y<5){
        ball->ball_vy=0;
        ball->ball_y=5;
    }
    else if(ball->ball_y>widget->height()-5){
        ball->ball_vy=0;
        ball->ball_y=widget->height()-5;
    }
}
void MainWindow::checkboard(ball* ball,board* board)
{
    if(ball->ball_x>board->x1&&ball->ball_x<board->x2){
        if(ball->ball_y>board->y1+5&&ball->ball_y<board->y2+5){
            ball->ball_vy=0;
            ball->ball_y=board->y2+5;
        }
        else if(ball->ball_y>board->y1-5&&ball->ball_y<board->y2-5){
            ball->ball_vy=0;
            ball->ball_y=board->y1-5;
        }
    }
    if(ball->ball_y>board->y1&&ball->ball_y<board->y2){
        if(ball->ball_x>board->x1+5&&ball->ball_x<board->x2+5){
            ball->ball_vx=0;
            ball->ball_x=board->x2+5;
        }
        else if(ball->ball_x>board->x1-5&&ball->ball_x<board->x2-5){
            ball->ball_vx=0;
            ball->ball_x=board->x1-5;
        }
    }
}
void MainWindow::checkbouncingboard(ball* ball,bouncingboard* B_board)
{
    if(ball->ball_x>B_board->x1&&ball->ball_x<B_board->x2){
        if(ball->ball_y>B_board->y1+5&&ball->ball_y<B_board->y2+5){
            ball->ball_vy*=-1;
            ball->ball_y=B_board->y2+5;
        }
        else if(ball->ball_y>B_board->y1-5&&ball->ball_y<B_board->y2-5){
            ball->ball_vy*=-1;
            ball->ball_y=B_board->y1-5;
        }
    }
    if(ball->ball_y>B_board->y1&&ball->ball_y<B_board->y2){
        if(ball->ball_x>B_board->x1+5&&ball->ball_x<B_board->x2+5){
            ball->ball_vx*=-1;
            ball->ball_x=B_board->x2+5;
        }
        else if(ball->ball_x>B_board->x1-5&&ball->ball_x<B_board->x2-5){
            ball->ball_vx*=-1;
            ball->ball_x=B_board->x1-5;
        }
    }
}
void MainWindow::checkvortex(ball* ball,vortex* vortex,QPixmap pix1,QPixmap pix2)
{
    QSize picSize(vortex->x2-vortex->x1,vortex->y2-vortex->y1);
    if(std::sqrt(ball->ball_vx*ball->ball_vx+ball->ball_vy*ball->ball_vy)>vortex->v_min){
        vortex->issafe=1;
        pix1=pix1.scaled(picSize);
        vortex->setPixmap(pix1);
    }
    else{
        vortex->issafe=0;
        pix2=pix2.scaled(picSize);
        vortex->setPixmap(pix2);
    }
    if(ball->ball_x>vortex->x1&&ball->ball_x<vortex->x2&&ball->ball_y>vortex->y1&&ball->ball_y<vortex->y2&&vortex->issafe==0){
        maintimer->stop();
        balltimer->stop();
        ball->ball_x=(vortex->x1+vortex->x2)/2;
        ball->ball_y=(vortex->y1+vortex->y2)/2;
        defeat(ball);
    }
}
void MainWindow::checkportal_a(ball* ball,portal_a* pa,portal_b* pb)
{
    if(ball->ball_x>pa->x1&&ball->ball_x<pa->x2&&ball->ball_y>pa->y1&&ball->ball_y<pa->y2){
        portal_transfer(ball,pa,pb);
    }
}


//键盘响应
void MainWindow::keyPressEvent(QKeyEvent* ev)
{
    if(mode==1){
        if(ev->key()==Qt::Key_A){
            emit Press_A();
            emit Press_A();
            qDebug()<<"pressA";
        }
        else if(ev->key()==Qt::Key_D){
            emit Press_D();
            emit Press_D();
            qDebug()<<"pressD";
        }
        if(ev->key()==Qt::Key_S){
            emit Press_S();
            emit Press_S();
            qDebug()<<"pressS";
        }
        else if(ev->key()==Qt::Key_W){
            emit Press_W();
            emit Press_W();
            qDebug()<<"pressW";
        }
    }
    else if(mode==2){
        if(ev->key()==Qt::Key_A){
            emit Press_A();
            emit Press_A();
            qDebug()<<"pressA";
        }
        else if(ev->key()==Qt::Key_D){
            emit Press_D();
            emit Press_D();
            qDebug()<<"pressD";
        }
        if(ev->key()==Qt::Key_K){
            emit Press_S();
            emit Press_S();
            qDebug()<<"pressS";
        }
        else if(ev->key()==Qt::Key_I){
            emit Press_W();
            emit Press_W();
            qDebug()<<"pressW";
        }
    }
    else if(mode==3){
        if(ev->key()==Qt::Key_A||ev->key()==Qt::Key_J){
            emit Press_A();
            qDebug()<<"pressA";
            if(ev->key()==Qt::Key_A){mode3_flag1++;mode3_flag2=0;}
            else{mode3_flag1=0;mode3_flag2++;}
        }
        else if(ev->key()==Qt::Key_D||ev->key()==Qt::Key_L){
            emit Press_D();
            qDebug()<<"pressD";
            if(ev->key()==Qt::Key_D){mode3_flag1++;mode3_flag2=0;}
            else{mode3_flag1=0;mode3_flag2++;}
        }
        if(ev->key()==Qt::Key_S||ev->key()==Qt::Key_K){
            emit Press_S();
            qDebug()<<"pressS";
            if(ev->key()==Qt::Key_S){mode3_flag1++;mode3_flag2=0;}
            else{mode3_flag1=0;mode3_flag2++;}
        }
        else if(ev->key()==Qt::Key_W||ev->key()==Qt::Key_I){
            emit Press_W();
            qDebug()<<"pressW";
            if(ev->key()==Qt::Key_W){mode3_flag1++;mode3_flag2=0;}
            else{mode3_flag1=0;mode3_flag2++;}
        }
    }
}

//主板轮廓
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter* painter=new QPainter(this);
    painter->setPen(QPen(Qt::gray,3));
    painter->setBrush(QBrush(Qt::gray));
    painter->drawLine(ui->widget->x1,ui->widget->y1,ui->widget->x1,ui->widget->y2);
    painter->drawLine(ui->widget->x1,ui->widget->y1,ui->widget->x2,ui->widget->y1);
    painter->drawLine(ui->widget->x1,ui->widget->y2,ui->widget->x2,ui->widget->y2);
    painter->drawLine(ui->widget->x2,ui->widget->y1,ui->widget->x2,ui->widget->y2);
    QPixmap pix;
    pix.load(":/mainbackground3.png");
    painter->drawPixmap(0,0,width,height,pix);
    painter->end();
    delete painter;
}

MainWindow::~MainWindow()
{
    delete ui;
}





























