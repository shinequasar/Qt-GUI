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

void Widget::turnOn(){
    ui->pbcoffee->setEnabled(true);
    ui->pbTea->setEnabled(true);
    ui->pbMilk->setEnabled(true);
}
void Widget::turnOut(){
    ui->pbcoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

void Widget::lightManager(){
    if(money>0) turnOn();
    else turnOut();
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
    QMessageBox m;
    m.information(nullptr,"BoB 자판기","초기화 되었습니다");
}
