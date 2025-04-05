#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

//every member variable and function declaration are created in .h file

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget(); //"distort"

    int money{0};//member variable->create variable per widget!!

    //void changeMoney(int diff);//qt use camel case for naming

private slots:
    /*
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pb_coffee100_clicked();

    void on_pb_milk500_clicked();

    void on_pb_tea300_clicked();
*/
    void Add(int diff);

    void on_pb_reset_clicked();



private:
    Ui::Widget *ui; //include everything that we can see in the screen
};
#endif // WIDGET_H
