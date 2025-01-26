#include "helpwidget.h"
#include "ui_helpwidget.h"

helpwidget::helpwidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::helpwidget)
{
    ui->setupUi(this);

    setWindowTitle("玩这个游戏之前你需要知道的");
    setWindowIcon(QIcon(":/notice.png"));
    ui->tabWidget->setCurrentWidget(ui->tab_1);
    connect(ui->pushButton_page1,&QPushButton::clicked,[=](){
        ui->tabWidget->setCurrentWidget(ui->tab_2);
    });
    connect(ui->pushButton_page2,&QPushButton::clicked,[=](){
        ui->tabWidget->setCurrentWidget(ui->tab_3);
    });
    connect(ui->btn_mode1,&QPushButton::clicked,[=](){
        this->close();
        emit mode1();
        ui->tabWidget->setCurrentWidget(ui->tab_1);
    });
    connect(ui->btn_mode2,&QPushButton::clicked,[=](){
        this->close();
        emit mode2();
        ui->tabWidget->setCurrentWidget(ui->tab_1);
    });
    connect(ui->btn_mode3,&QPushButton::clicked,[=](){
        this->close();
        emit mode3();
        ui->tabWidget->setCurrentWidget(ui->tab_1);
    });

    ui->textEdit_rule->setReadOnly(1);
    ui->textEdit_1->setReadOnly(1);
    ui->textEdit_2->setReadOnly(1);
    ui->textEdit_3->setReadOnly(1);
    ui->textEdit_4->setReadOnly(1);
    ui->textEdit_5->setReadOnly(1);
    ui->textEdit_6->setReadOnly(1);
    ui->textEdit_7->setReadOnly(1);
    ui->textEdit_mode->setReadOnly(1);

    QPixmap pix;
    QSize picSize;

    picSize.setWidth(ui->ball_label->width()),picSize.setHeight(ui->ball_label->height());
    pix.load(":/ball.png");
    pix=pix.scaled(picSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->ball_label->setPixmap(pix);

    pix.load(":/flag.png");
    picSize.setWidth(ui->dest_label->width()),picSize.setHeight(ui->dest_label->height());
    pix=pix.scaled(picSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->dest_label->setPixmap(pix);

    pix.load(":/trap.png");
    picSize.setWidth(ui->trap_label->width()),picSize.setHeight(ui->trap_label->height());
    pix=pix.scaled(picSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->trap_label->setPixmap(pix);

    pix.load(":/board.png");
    picSize.setWidth(ui->board_label->width()),picSize.setHeight(ui->board_label->height());
    pix=pix.scaled(picSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->board_label->setPixmap(pix);

    pix.load(":/bouncingboard.png");
    picSize.setWidth(ui->bouncingboard_label->width()),picSize.setHeight(ui->bouncingboard_label->height());
    pix=pix.scaled(picSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->bouncingboard_label->setPixmap(pix);

    pix.load(":/vortex.png");
    picSize.setWidth(ui->bouncingboard_label->width()),picSize.setHeight(ui->bouncingboard_label->height());
    pix=pix.scaled(picSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->vortex_label->setPixmap(pix);

    pix.load(":/inportal0.png");
    picSize.setWidth(ui->bouncingboard_label->width()),picSize.setHeight(ui->bouncingboard_label->height());
    pix=pix.scaled(picSize,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    ui->portal_label->setPixmap(pix);
}

helpwidget::~helpwidget()
{
    delete ui;
}
