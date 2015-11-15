#include "gamewidget.h"
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
gamewidget::gamewidget(QWidget *parent) : QWidget(parent)
{
    this->setAutoFillBackground(true);//覆盖
    this->resize(580,340);
    this->setWindowIcon(QIcon("image/snake.ico"));
    this->setWindowTitle("贪吃蛇");

    QPalette palette2;
    QBrush brush1(QPixmap("image/bj.jpg").scaled(580,340));
    palette2.setBrush(QPalette::Background,brush1);
    this->setPalette(palette2);
//    //按钮区
    Leftbtn = new QPushButton(QIcon("image/left.png"),"",this);
    Leftbtn->setIconSize(QSize(35,35));
    Leftbtn->setGeometry(425,150,35,35);
    Leftbtn->setFlat(true);

    Rightbtn = new QPushButton(QIcon("image/right.png"),"",this);
    Rightbtn->setIconSize(QSize(35,35));
    Rightbtn->setGeometry(505,150,35,35);
    Rightbtn->setFlat(true);

    Upbtn = new QPushButton(QIcon("image/up.png"),"",this);
    Upbtn->setIconSize(QSize(35,35));
    Upbtn->setGeometry(465,110,35,35);
    Upbtn->setFlat(true);


    Downbtn = new QPushButton(QIcon("image/down.png"),"",this);
    Downbtn->setIconSize(QSize(35,35));
    Downbtn->setGeometry(465,190,35,35);
    Downbtn->setFlat(true);

    Startbtn = new QPushButton(QIcon("image/ks.png"),"",this);
    Startbtn->setIconSize(QSize(35,35));
    Startbtn->setGeometry(415,270,35,35);
    Startbtn->setFlat(true);


    Pausebtn = new QPushButton(QIcon("image/zt.png"),"",this);
    Pausebtn->setIconSize(QSize(35,35));
    Pausebtn->setGeometry(465,270,35,35);
    Pausebtn->setFlat(true);

    Exitbtn = new QPushButton(QIcon("image/fh.png"),"",this);
    Exitbtn->setIconSize(QSize(35,35));
    Exitbtn->setGeometry(515,270,35,35);
    Exitbtn->setFlat(true);

//    //连接信号和槽
    connect(Leftbtn,SIGNAL(clicked(bool)),this,SLOT(Leftbtn_click()));
    connect(Rightbtn,SIGNAL(clicked(bool)),this,SLOT(Rightbtn_click()));
    connect(Upbtn,SIGNAL(clicked(bool)),this,SLOT(Upbtn_cliak()));
    connect(Downbtn,SIGNAL(clicked(bool)),this,SLOT(Downbtn_click()));
    connect(Startbtn,SIGNAL(clicked(bool)),this,SLOT(Startbtn_click()));
    connect(Pausebtn,SIGNAL(clicked(bool)),this,SLOT(Pausebtn_click()));
    connect(Exitbtn,SIGNAL(clicked(bool)),this,SLOT(Exitbtn_click()));


    //设置起始信息
    QTime tim1;
    tim1 = QTime().currentTime();
    int seed = tim1.second();
    qsrand(seed);
    snake[0][0] = qrand()%12;
    snake[0][1] = qrand()%10;
    Drec = qrand()%4;
    FoodPostion();
    foodnum = 0;
    score = 0;
    //设置时钟
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(Timer_out()));

}

//gamewidget::~gamewidget()
//{


//    delete Rightbtn;
//    delete Upbtn;
//    delete Downbtn;
//    delete Startbtn;
//    delete Pausebtn;
//    delete Exitbtn;
//    delete timer1;

//}

void gamewidget::Leftbtn_click()
{
    Drec = LEFT;

}

void gamewidget::Downbtn_click()
{
    Drec = DOWN;

}

void gamewidget::Rightbtn_click()
{
    Drec = RIGHT;

}

void gamewidget::Upbtn_cliak()
{
    Drec = UP;

}

void gamewidget::Startbtn_click()
{

    timer1->start(500);

}

void gamewidget::Pausebtn_click()
{
    timer1->stop();


}

void gamewidget::Exitbtn_click()
{
    delete this;

}

void gamewidget::Timer_out()
{
    //判断是否吃到食物
    if(snake[0][0]==foodx && snake[0][1]==foody)
    {
        //食物数量+1
        foodnum++;
        score++;
        //重新产生食物坐标
        FoodPostion();

    }
    for(int i=foodnum;i>0;i--)
    {
        snake[i][0] = snake[i-1][0];
        snake[i][1] = snake[i-1][1];
    }


    switch (Drec) {
    case LEFT:
        snake[0][0]--;

        break;
    case DOWN:
        snake[0][1]++;
        break;
    case UP:
        snake[0][1]--;
        break;
    case RIGHT:
        snake[0][0]++;
        break;
    default:
        break;
    }

    //判断蛇是否越界
   if(snake[0][0]<0 || snake[0][0]>14 || snake[0][1]<0 || snake[0][1]>14)
   {
       timer1->stop();
       QMessageBox().information(this,"提示","Game Over!");
       //设置起始信息
       QTime tim1;
       tim1 = QTime().currentTime();
       int seed = tim1.second();
       qsrand(seed);
       snake[0][0] = qrand()%12;
       snake[0][1] = qrand()%10;
       Drec = qrand()%4;
       FoodPostion();
       foodnum = 0;
       return;
   }
   //判断是否自尽
   for(int i=1;i<foodnum+1;i++)
   {
       if(snake[0][0]==snake[i][0] && snake[0][1] == snake[i][1])
       {
           timer1->stop();
           QMessageBox().information(this,"提示","Game Over!");
           //设置起始信息
           QTime tim1;
           tim1 = QTime().currentTime();
           int seed = tim1.second();
           qsrand(seed);
           snake[0][0] = qrand()%12;
           snake[0][1] = qrand()%10;
           Drec = qrand()%4;
           FoodPostion();
           foodnum = 0;
           return;
       }
   }



   //重画游戏画面
    this->update();
}

void gamewidget::FoodPostion()
{
    QTime tim1;
    int seed;
    do
    {
        tim1 = QTime().currentTime();
        seed = tim1.second();
        qsrand(seed);
        foodx = qrand()%15;
        foody = qrand()%13;
    }while (IsinSnake(foodx,foody)==true);

}

bool gamewidget::IsinSnake(int x, int y)
{
    for(int i=0;i<foodnum+1;i++)
    {
        if(snake[i][0] == x && snake[i][1] == y)
        {
            return true;
        }
    }
    return false;
}

void gamewidget::paintEvent(QPaintEvent *)
{

    //画网格
    QPainter painter(this);
    for(int i=0;i<14;i++)
    {
        painter.drawLine(7,7+i*25,382,7+i*25);
    }
    for(int j=0;j<16;j++)
    {
        painter.drawLine(7+j*25,7,7+j*25,332);
    }



     //画食物
     painter.drawImage(QRectF(8+foodx*25,8+foody*25,24,24),QImage("image/food.png"));

     // 画分数
     QFont font1;
     font1.setPointSize(20);
     painter.setFont(font1);
     QString scostr;
     painter.drawText(QRectF(420,40,80,30),"Score:");
     painter.drawText(QRectF(510,42,80,30),scostr.number(score));

     //画蛇

     for(int i=0;i<foodnum+1;i++)
     {
       painter.drawImage(QRectF(8+snake[i][0]*25,8+snake[i][1]*25,24,24),QImage("image/fk.png"));
     }


}
