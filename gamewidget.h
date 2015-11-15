#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QPoint>
#include <QRect>
#include <QRectF>
#include <QImage>
#include <QFont>
class gamewidget : public QWidget
{
    Q_OBJECT
public:
    explicit gamewidget(QWidget *parent = 0);
    //~gamewidget();
    void paintEvent(QPaintEvent *);
    void FoodPostion();
    bool IsinSnake(int x,int y);
private:
    QPushButton *Leftbtn;
    QPushButton *Downbtn;
    QPushButton *Upbtn;
    QPushButton *Rightbtn;
    QPushButton *Startbtn;
    QPushButton *Pausebtn;
    QPushButton *Exitbtn;

    //食物坐标
    int foodx;
    int foody;
    //食物数量;
    int foodnum;
    //起始方向
    int Drec;

    //时钟控件
    QTimer *timer1;

    //蛇坐标数组
    int snake[100][2];

    //分数
    int score;


public slots:
    void Leftbtn_click();
    void Rightbtn_click();
    void Upbtn_cliak();
    void Downbtn_click();
    void Startbtn_click();
    void Pausebtn_click();
    void Exitbtn_click();
    void Timer_out();
};

#endif // GAMEWIDGET_H
