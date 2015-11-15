#include "mainwidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(580,340);
    this->setWindowIcon(QIcon("image/snake.ico"));
    this->setWindowTitle("贪吃蛇");

    QPalette palette1;
    QBrush brush1(QPixmap("image/hqg.jpg").scaled(580,340));
    palette1.setBrush(QPalette::Background,brush1);
    this->setPalette(palette1);
    button1 = new QPushButton(QIcon("image/ks.png"),"",this);
    button1->setIconSize(QSize(35,35));
    button1->setGeometry(480,275,35,35);
    button1->setFlat(true);

    button2 = new QPushButton(QIcon("image/gb.png"),"",this);
    button2->setIconSize(QSize(35,35));
    button2->setGeometry(530,275,35,35);
    button2->setFlat(true);

    this->connect(button1,SIGNAL(clicked(bool)),this,SLOT(startbtn_click()));
    this->connect(button2,SIGNAL(clicked(bool)),this,SLOT(exitbtn_click()));

}

mainWidget::~mainWidget()
{
    delete button1;
    delete button2;

}


void mainWidget::startbtn_click()
{
//    game1 = new gamewidget();
//    game1->show();
    GameJm = new gamewidget(this);
    GameJm->show();

}

void mainWidget::exitbtn_click()
{
    if(QMessageBox::question(this,"提示框","你确定要退出游戏吗？")==QMessageBox::Yes)
    exit(0);
}




