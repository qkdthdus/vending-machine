#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

//int money{0}; //global->multuple wiget make error

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pb_reset->setEnabled(false);

    connect(ui->pb10, &QPushButton::clicked, [=](){ Add(10); });
    connect(ui->pb50, &QPushButton::clicked, [=](){ Add(50); });
    connect(ui->pb100, &QPushButton::clicked, [=](){ Add(100); });
    connect(ui->pb500, &QPushButton::clicked, [=](){ Add(500); });
    connect(ui->pb_coffee100, &QPushButton::clicked, [=](){ Add(-100); });
    connect(ui->pb_tea300, &QPushButton::clicked, [=](){ Add(-300); });
    connect(ui->pb_milk500, &QPushButton::clicked, [=](){ Add(-500); });

}

Widget::~Widget()
{
    delete ui;
}
/*
void Widget::changeMoney(int diff) {
    if (money + diff > 0) { // 돈이 음수가 되지 않도록 체크
        money += diff;
        ui->lcdNumber->display(money);
    }
    else {
        QMessageBox::warning(this, "경고", "잔액이 부족합니다.");
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pb_coffee100_clicked()
{
    changeMoney(-100);
}


void Widget::on_pb_milk500_clicked()
{
    changeMoney(-500);
}

void Widget::on_pb_tea300_clicked()
{
    changeMoney(-300);
}
*/

void Widget::Add(int diff){
    if (money + diff >= 0) { // 돈이 음수가 되지 않도록 체크
        money += diff;
        ui->lcdNumber->display(money);
        ui->pb_reset->setEnabled(true);
    }
    else {
        QMessageBox::warning(this, "경고", "잔액이 부족합니다.");
    }
}

void Widget::on_pb_reset_clicked()
{
    if (money > 0) {
        int m=money;
        int m500=m/500; m-=m500*500;
        int m100=m/100; m-=m100*100;
        int m50=m/50; m-=m50*50;
        int m10=m/10; m-=m10*10;

        QString message = QString("총 %1원이 반환되었습니다.\n\n[거스름돈]\n500원: %2개\n100원: %3개\n50원: %4개\n10원: %5개").arg(money).arg(m500).arg(m100).arg(m50).arg(m10);
        QMessageBox::information(this, "돈 반환", message);

        // 반환 후 잔액을 0으로 설정
        money = 0;
        ui->lcdNumber->display(money);
    } else {
        QMessageBox::information(this, "알림", "반환할 금액이 없습니다.");
    }
}



