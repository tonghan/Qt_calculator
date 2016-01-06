#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QStringList>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QLineEdit *show_reslut;  //显示按键的值
     QLineEdit *show_process; //显示运算过程
     QPushButton *button_0;
     QPushButton *button_1;
     QPushButton *button_2;
     QPushButton *button_3;
     QPushButton *button_4;
     QPushButton *button_5;
     QPushButton *button_6;
     QPushButton *button_7;
     QPushButton *button_8;
     QPushButton *button_9;
     QPushButton *button_dot;
     QPushButton *button_CE;
     QPushButton *button_equ;
     QPushButton *button_plus;
     QPushButton *button_sub;
     QPushButton *button_mul;
     QPushButton *button_div;

//     QPushButton *Calcutor;
     QString  Res_show="0";//运算的第一个数
     QString  Res_show2="0";//运算的第二个数
     QString  Res_show_process="0";//用于显示操作步骤
     char Logic_operator=' '; //保存按下的运算符

     bool dot_flag = false;//小数点加载的标志位
     bool ope_flag = false;//按下运算符的标志位
     bool neg_flag = false;//负号标志位
     bool over_flag= false;//已经按了"="号，再输入数字，需清屏

private slots:
     void button_0_clicked();   // 0
     void button_1_clicked(); //1
     void button_2_clicked();//2
     void button_3_clicked();//3
     void button_4_clicked();//4
     void button_5_clicked();//5
     void button_6_clicked();//6
     void button_7_clicked();//7
     void button_8_clicked();//8
     void button_9_clicked();//9
     void button_dot_clicked();//   "."
     void button_CE_clicked();//CE
     void button_equ_clicked();// "="
     void button_plus_clicked();// "+"
     void button_sub_clicked();//"-"
     void button_mul_clicked();//"*"
     void button_div_clicked();//"/"

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
