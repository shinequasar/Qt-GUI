#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money {0};
    void changeMoney(int diff);
    void subMoney(int diff);
    void turnOn(int diff);
    void turnOut();
    void lightManager();

private slots:
    void on_pb10_1_clicked();

    void on_pb10_2_clicked();

    void on_pb10_3_clicked();

    void on_pb10_4_clicked();

    void on_pbcoffee_clicked();

    void on_pbTea_clicked();

    void on_pbMilk_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
