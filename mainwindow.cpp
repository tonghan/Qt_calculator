#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget*parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);

    setWindowTitle(tr("计算器"));

    show_reslut=new QLineEdit("0");
    show_process =new QLineEdit("0");

    show_reslut->setAlignment(Qt::AlignRight);  //右对齐
    show_process->setAlignment(Qt::AlignRight);

    show_reslut->setReadOnly(true);//readonly
    show_process->setReadOnly(true);

    button_0 =new QPushButton("0");
    button_1 =new QPushButton("1");
    button_2 =new QPushButton("2");
    button_3 =new QPushButton("3");
    button_4 =new QPushButton("4");
    button_5 =new QPushButton("5");
    button_6 =new QPushButton("6");
    button_7 =new QPushButton("7");
    button_8 =new QPushButton("8");
    button_9 =new QPushButton("9");
    button_dot =new QPushButton(".");
    button_CE=new QPushButton("CE");
    button_plus =new QPushButton("+");
    button_mul =new QPushButton("*");
    button_div =new QPushButton("/");
    button_sub =new QPushButton("-");
    button_equ =new QPushButton("=");

    /*
     * 布局
     */

    QHBoxLayout *Hor1=new QHBoxLayout;
    QHBoxLayout *Hor2=new QHBoxLayout;
    QHBoxLayout *Hor3=new QHBoxLayout;
    QHBoxLayout *Hor4=new QHBoxLayout;
    QHBoxLayout *Hor5=new QHBoxLayout;
    QHBoxLayout *Hor6=new QHBoxLayout;

    Hor6->addWidget(show_process);

    Hor1->addWidget(show_reslut);
    Hor1->addWidget(button_CE);

    Hor2->addWidget(button_1);
    Hor2->addWidget(button_2);
    Hor2->addWidget(button_3);
    Hor2->addWidget(button_plus);

    Hor3->addWidget(button_4);
    Hor3->addWidget(button_5);
    Hor3->addWidget(button_6);
    Hor3->addWidget(button_sub);

    Hor4->addWidget(button_7);
    Hor4->addWidget(button_8);
    Hor4->addWidget(button_9);
    Hor4->addWidget(button_mul);

    Hor5->addWidget(button_dot);
    Hor5->addWidget(button_0);
    Hor5->addWidget(button_equ);
    Hor5->addWidget(button_div);



    QVBoxLayout *V1=new QVBoxLayout;
    V1->addLayout(Hor6);
    V1->addLayout(Hor1);
    V1->addLayout(Hor2);
    V1->addLayout(Hor3);
    V1->addLayout(Hor4);
    V1->addLayout(Hor5);
/*
 *  信号槽函数
 */
    connect(button_0,SIGNAL(clicked()),this,SLOT(button_0_clicked()));
    connect(button_1,SIGNAL(clicked()),this,SLOT(button_1_clicked()));
    connect(button_2,SIGNAL(clicked()),this,SLOT(button_2_clicked()));
    connect(button_3,SIGNAL(clicked()),this,SLOT(button_3_clicked()));
    connect(button_4,SIGNAL(clicked()),this,SLOT(button_4_clicked()));
    connect(button_5,SIGNAL(clicked()),this,SLOT(button_5_clicked()));
    connect(button_6,SIGNAL(clicked()),this,SLOT(button_6_clicked()));
    connect(button_7,SIGNAL(clicked()),this,SLOT(button_7_clicked()));
    connect(button_8,SIGNAL(clicked()),this,SLOT(button_8_clicked()));
    connect(button_9,SIGNAL(clicked()),this,SLOT(button_9_clicked()));
    connect(button_dot,SIGNAL(clicked()),this,SLOT(button_dot_clicked()));
    connect(button_CE,SIGNAL(clicked()),this,SLOT(button_CE_clicked()));
    connect(button_equ,SIGNAL(clicked()),this,SLOT(button_equ_clicked()));
    connect(button_plus,SIGNAL(clicked()),this,SLOT(button_plus_clicked()));
    connect(button_sub,SIGNAL(clicked()),this,SLOT(button_sub_clicked()));
    connect(button_mul,SIGNAL(clicked()),this,SLOT(button_mul_clicked()));
    connect(button_div,SIGNAL(clicked()),this,SLOT(button_div_clicked()));

    setLayout(V1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_CE_clicked()    //清屏,各标志位恢复默认值
{
    Res_show="0";
    Res_show2="0";
    show_reslut->setText(Res_show);
    show_process->setText(Res_show);
    dot_flag=false;
    neg_flag=false;
     ope_flag = false;
     over_flag =false;
    Logic_operator=' ';
}

void MainWindow::button_0_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("0");
        show_process->setText("0");
    }
    else {
        if(ope_flag)
            show_reslut->setText(Res_show);
        Res_show = show_reslut->text();
        if( Res_show !="0" ) {
            Res_show.append('0');
            show_reslut->setText(Res_show);
        }
        else {
            Res_show ="0";
            show_reslut->setText(Res_show);
        }

        Res_show_process=show_process->text();
        if(Res_show_process == "0")
            Res_show_process="0";
        else
            Res_show_process.append("0");
        show_process->setText(Res_show_process);
    }
    over_flag=false;
    ope_flag=false;
}

void MainWindow::button_1_clicked()
{
    if(over_flag) {                               //如果按下“=”号后，需要清屏，及显示键值
        MainWindow::button_CE_clicked();
        show_reslut->setText("1");
        show_process->setText("1");
    }
    else {
        if(ope_flag)   //如果之前按下运算操作符
            show_reslut->setText(Res_show);
        Res_show = show_reslut->text();
        if( Res_show == "0" ) //如果界面显示为”0“，需要将当前键值替换”0“
            Res_show = "1";
        else
            Res_show.append("1");//否则在后面添加当前键值
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text(); //Same as above
        if(Res_show_process == "0")
            Res_show_process="1";
        else
            Res_show_process.append("1");
        show_process->setText(Res_show_process);
        }
    ope_flag=false;
    over_flag=false;
}

void MainWindow::button_2_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("2");
        show_process->setText("2");
    }
    else {
        if(ope_flag)
            show_reslut->setText(Res_show);
        Res_show = show_reslut->text();
        if( Res_show == "0" )
            Res_show = "2";
        else
            Res_show.append("2");
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text();
        if(Res_show_process == "0")
            Res_show_process="2";
        else
            Res_show_process.append("2");
        show_process->setText(Res_show_process);
    }
     ope_flag=false;
     over_flag=false;
}
void MainWindow::button_3_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("3");
        show_process->setText("3");
    }
    else {
        if(ope_flag)
            show_reslut->setText(Res_show);
        Res_show = show_reslut->text();
        if( Res_show == "0" )
            Res_show = "3";
        else
            Res_show.append("3");
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text();
        if(Res_show_process == "0")
            Res_show_process="3";
        else
            Res_show_process.append("3");
        show_process->setText(Res_show_process);
    }
     ope_flag=false;
     over_flag=false;
}
void MainWindow::button_4_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("4");
        show_process->setText("4");
    }
    else {
        if(ope_flag)
            show_reslut->setText(Res_show);
        Res_show = show_reslut->text();
        if( Res_show == "0" )
            Res_show = "4";
        else
            Res_show.append("4");
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text();
        if(Res_show_process == "0")
            Res_show_process="4";
        else
            Res_show_process.append("4");
        show_process->setText(Res_show_process);
    }
     ope_flag=false;
     over_flag=false;
}
void MainWindow::button_5_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("5");
        show_process->setText("5");
    }
    else {
    if(ope_flag)
         show_reslut->setText(Res_show);
    Res_show = show_reslut->text();
    if( Res_show == "0" )
        Res_show = "5";
    else
        Res_show.append("5");
    show_reslut->setText(Res_show);

    Res_show_process=show_process->text();
    if(Res_show_process == "0")
        Res_show_process="5";
    else
        Res_show_process.append("5");
    show_process->setText(Res_show_process);
    }
     ope_flag=false;
     over_flag=false;
}
void MainWindow::button_6_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("6");
        show_process->setText("6");
    }
    else {
        if(ope_flag)
            show_reslut->setText(Res_show);
        Res_show = show_reslut->text();
        if( Res_show == "0" )
            Res_show = "6";
        else
            Res_show.append("6");
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text();
        if(Res_show_process == "0")
            Res_show_process="6";
        else
            Res_show_process.append("6");
        show_process->setText(Res_show_process);
    }
     ope_flag=false;
     over_flag =false;
}
void MainWindow::button_7_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("7");
        show_process->setText("7");
    }
    else {
        if(ope_flag)
            show_reslut->setText(Res_show);
        Res_show = show_reslut->text();
        Res_show_process=show_process->text();
        if( Res_show == "0" )
            Res_show = "7";
        else
            Res_show.append("7");
        show_reslut->setText(Res_show);

        if(Res_show_process == "0")
            Res_show_process="7";
        else
            Res_show_process.append("7");
        show_process->setText(Res_show_process);
        }
     ope_flag=false;
     over_flag=false;
}
void MainWindow::button_8_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("8");
        show_process->setText("8");
    }
    else{
    if(ope_flag)
         show_reslut->setText(Res_show);
    Res_show = show_reslut->text();
    Res_show_process=show_process->text();
    if( Res_show == "0" )
        Res_show = "8";
    else
        Res_show.append("8");
    show_reslut->setText(Res_show);

    if(Res_show_process == "0")
        Res_show_process="8";
    else
        Res_show_process.append("8");
    show_process->setText(Res_show_process);
}
     ope_flag=false;
     over_flag=false;
}
void MainWindow::button_9_clicked()
{
    if(over_flag) {
        MainWindow::button_CE_clicked();
        show_reslut->setText("9");
        show_process->setText("9");
    }
    else{
        if(ope_flag )
            show_reslut->setText(Res_show);

        Res_show = show_reslut->text();
        Res_show_process=show_process->text();
        if( Res_show == "0" )
            Res_show = "9";
        else
            Res_show.append("9");
        show_reslut->setText(Res_show);

        if(Res_show_process == "0")
            Res_show_process="9";
        else
            Res_show_process.append("9");
        show_process->setText(Res_show_process);
    }
     ope_flag=false;
     over_flag=false;
}
void MainWindow::button_dot_clicked() //小数点
{
    if(over_flag) {     //如果是按过“=”号后，再按任一数字键及小数点后，需要清屏及显示当前键值
        MainWindow::button_CE_clicked();
        show_reslut->setText("0.");
        show_process->setText("0.");
    }
    else {
        if(ope_flag)
            show_reslut->setText(Res_show);
        if( ! dot_flag ) {
            Res_show = show_reslut->text();
            Res_show_process=show_process->text();
            if(Res_show == "0")
                Res_show_process.append("0");
            Res_show.append(".");
            show_reslut->setText(Res_show);
            Res_show_process.append(".");
            show_process->setText(Res_show_process);

            dot_flag=true;
        }
    }
    ope_flag=false;
    over_flag=false;
}

void MainWindow::button_equ_clicked()   //等于号
{
    double temp1,temp2;
    if (Logic_operator == ' ') {
        Res_show2=Res_show;
        Logic_operator = ' ';
        show_reslut->setText(Res_show2);
    }
    else {

        temp1 = Res_show2.toDouble();
        if (neg_flag)
            temp2 = (-1)*Res_show.toDouble();
        else
            temp2 = Res_show.toDouble();
        switch (Logic_operator) {
        case '+':
            temp1=temp1+temp2;
            break;
         case '-':
            temp1=temp1-temp2;
            break;
         case '*':
            temp1=temp1*temp2;
            break;
         case '/':
            temp1=temp1/temp2;
            break;
        default:
           break;
        }
        Res_show2=QString::number(temp1);
        Res_show = Res_show2;
        show_reslut->setText(Res_show2);
        Logic_operator=' ';
    }
    dot_flag=false;
    ope_flag = false;
    neg_flag=false;
    over_flag=true;
}
void MainWindow::button_plus_clicked()        //加法
{
    double temp1,temp2;
    if (Logic_operator == ' ') {  //如果当前键值为第一个被按的
        Res_show2=Res_show;
        Logic_operator = '+';
        Res_show = "0";
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text();
        Res_show_process.append("+");
        show_process->setText(Res_show_process);

    }
    else {

        Res_show_process=show_process->text();
        Res_show_process.append("+");
        show_process->setText(Res_show_process);

        temp1 = Res_show2.toDouble();
        if (neg_flag)   //如果负号标志置位了
            temp2 = (-1)*Res_show.toDouble();
        else
            temp2 = Res_show.toDouble();
        switch (Logic_operator) {
        case '+':
            temp1=temp1+temp2;
            break;
         case '-':
            temp1=temp1-temp2;
            break;
         case '*':
            temp1=temp1*temp2;
            break;
         case '/':
            temp1=temp1/temp2;
            break;
        default:
           break;
        }

        Res_show2=QString::number(temp1);
        Res_show = "0";
        show_reslut->setText(Res_show2);
        Logic_operator='+';
    }
    dot_flag=false;
    ope_flag = true;
    neg_flag=false;
    over_flag=false;
}
void MainWindow::button_div_clicked()   //除法
{
    double temp1,temp2;
    if (Logic_operator == ' ') {
        Res_show2=Res_show;
        Logic_operator = '/';
        Res_show = "0";
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text();
        Res_show_process.append("/");
        show_process->setText(Res_show_process);

    }
    else {

        Res_show_process=show_process->text();
        Res_show_process.append("/");
        show_process->setText(Res_show_process);

        temp1 = Res_show2.toDouble();
        if (neg_flag)
            temp2 = (-1)*Res_show.toDouble();
        else
            temp2 = Res_show.toDouble();
        switch (Logic_operator) {
        case '+':
            temp1=temp1+temp2;
            break;
         case '-':
            temp1=temp1-temp2;
            break;
         case '*':
            temp1=temp1*temp2;
            break;
         case '/':
            temp1=temp1/temp2;
            break;
         default:
            break;
        }

         Res_show2=QString::number(temp1);
        Res_show = "0";
        show_reslut->setText(Res_show2);
        Logic_operator='/';
    }
    dot_flag=false;
    ope_flag = true;
    neg_flag=false;
    over_flag=false;
}
void MainWindow::button_mul_clicked()  //乘法
{
    double temp1,temp2;
    if (Logic_operator == ' ') {
        Res_show2=Res_show;
        Logic_operator = '*';
        Res_show = "0";
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text();
        Res_show_process.append("*");
        show_process->setText(Res_show_process);

    }
    else {

        Res_show_process=show_process->text();
        Res_show_process.append("*");
        show_process->setText(Res_show_process);

        temp1 = Res_show2.toDouble();
        if (neg_flag)
            temp2 = (-1)*Res_show.toDouble();
        else
            temp2 = Res_show.toDouble();
        switch (Logic_operator) {
        case '+':
            temp1=temp1+temp2;
            break;
         case '-':
            temp1=temp1-temp2;
            break;
         case '*':
            temp1=temp1*temp2;
            break;
         case '/':
            temp1=temp1/temp2;
            break;
        default:
           break;
        }

         Res_show2=QString::number(temp1);
        Res_show = "0";
        show_reslut->setText(Res_show2);
        Logic_operator='*';
    }
    dot_flag=false;
    ope_flag = true;
    neg_flag=false;
    over_flag=false;
}
void MainWindow::button_sub_clicked()  //减法
{
   double temp1,temp2;
   if (Logic_operator == ' ') {
        Res_show2=Res_show;
        Logic_operator = '-';
        Res_show = "0";
        show_reslut->setText(Res_show);

        Res_show_process=show_process->text();
        Res_show_process.append("-");
        show_process->setText(Res_show_process);

    }
   else if (ope_flag){  //如果之前的按键为操作符，那么再按”-“，就相当于为负号操作
        neg_flag = true;//负号标志置位
        Res_show_process=show_process->text();
        Res_show_process.append("-");
        show_process->setText(Res_show_process);
    }
   else {
       Res_show_process=show_process->text();
       Res_show_process.append("-");
       show_process->setText(Res_show_process);
       temp1 = Res_show2.toDouble();
       temp2 = Res_show.toDouble();
       switch (Logic_operator) {
        case '+':
            temp1=temp1+temp2;
            break;
         case '-':
            temp1=temp1-temp2;
            break;
         case '*':
            temp1=temp1*temp2;
            break;
         case '/':
            temp1=temp1/temp2;
            break;
        default:
           break;
        }
        Res_show2=QString::number(temp1);
        Res_show = "0";
        show_reslut->setText(Res_show2);
        Logic_operator='-';
    }
    dot_flag=false;
    ope_flag = true;
  //  neg_flag=false;
   over_flag=false;
}

