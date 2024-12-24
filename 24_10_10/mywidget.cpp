#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * btn =new QPushButton;
    btn->setParent(this);//设置父亲，让btn对象依赖在myWidget窗口中
    btn->setText("First Button");//显示文本

    //以控件大小加载窗口
    QPushButton *btn2=new QPushButton("Second Button",this);

    //移动btn2
    btn2->move(100,100);

    //重置窗口大小
    resize(600,400);

    //固定窗口大小
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("First Window");

    //创建一个我自己的按钮对象
    MyPushButton *mybtn = new MyPushButton;
    mybtn->setText("MyButton");
    mybtn->move(200,200);
    mybtn->setParent(this);


    //需求  点击mybtn关闭窗口
    //参数1  信号的发送者  参数2 发送的信号(函数的地址)  参数3  信号的接受者  参数4 处理的槽函数
    connect(mybtn,&MyPushButton::clicked,this,&myWidget::close);
    //connect(mybtn,&QPushButton::clicked,this,&QWidget::close);用父类也一样
}

myWidget::~myWidget() {}
