#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    turnOut();
}

Widget::~Widget()
{
    delete ui;
}

int money = 0;

void Widget::turnOn(int price){
    switch (price) {
       case 100:
           ui->pbcoffee->setEnabled(true);
           break;
       case 150:
           ui->pbTea->setEnabled(true);
           break;
        case 200:
            ui->pbMilk->setEnabled(true);
            break;
    }
}
void Widget::turnOut(){
           ui->pbcoffee->setEnabled(false);
           ui->pbTea->setEnabled(false);
           ui->pbMilk->setEnabled(false);
    }



void Widget::lightManager(){
    if(money<100) turnOut();
    else if(money<150) {
        turnOut();
        turnOn(100);
    }
    else if(money<200) {
        turnOut();
        turnOn(100);
        turnOn(150);
    }
    else if(money>=200) {
        turnOut();
        turnOn(100);
        turnOn(150);
        turnOn(200);
    }
}

void Widget::changeMoney(int price){
    money += price;
    ui->lcdNumber->display(money);
    lightManager();
}

void Widget::subMoney(int price){
    money -= price;
    ui->lcdNumber->display(money);
    lightManager();
}

void Widget::on_pb10_1_clicked()
{
    changeMoney(10);
}

void Widget::on_pb10_2_clicked()
{
    changeMoney(50);
}

void Widget::on_pb10_3_clicked()
{
    changeMoney(100);
}

void Widget::on_pb10_4_clicked()
{
    changeMoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    subMoney(100);
}

void Widget::on_pbTea_clicked()
{
    subMoney(150);
}

void Widget::on_pbMilk_clicked()
{
    subMoney(200);
}

void Widget::on_pbReset_clicked()
{
    money=0;
    ui->lcdNumber->display(money);
    lightManager();
    QMessageBox m;
    m.information(nullptr,"BoB 자판기","초기화 되었습니다");
}
