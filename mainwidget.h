#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPushButton>
#include <QMessageBox>
#include <gamewidget.h>
class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = 0);
    ~mainWidget();
    gamewidget *game1;
    gamewidget *GameJm;
private:
    QPushButton *button1;
    QPushButton *button2;
public slots:
    void startbtn_click();
    void exitbtn_click();
};



#endif // MAINWIDGET_H
