#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
//Teacher 类
//Student 类
//下课后，老师会触发信号“饿了”，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建老师对象
    this->zt=new Teacher(this);

    //创建学生对象
    this->st=new Student(this);

    // //连接
    // connect(zt,&Teacher::hungry,st,&Student::treat);

    // //调用下课函数
    // classIsOver();

    //连接带参数的信号和槽
    //函数指针->函数地址
    //自定义信号和槽发生重载的解决：通过指针
    void(Teacher::*teacherSignal)(QString)=&Teacher::hungry;
    void(Student::*studentSlot)(QString)=&Student::treat;
    connect(zt,teacherSignal,st,studentSlot);
    classIsOver();

    //点击一个下课的按钮，再触发下课
    //信号与信号的连接
    QPushButton *btn=new QPushButton("下课",this);
    //重置窗口大小
    this->resize(600,400);
    //点击按钮触发下课
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);


    //无参信号和槽连接
    void(Teacher::*teacherSignal2)()=&Teacher::hungry;
    void(Student::*studentSlot2)()=&Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);
    //信号连接信号
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);

    //断开信号
    //disconnect(zt,teacherSignal2,st,studentSlot2);

    //拓展
    //1.信号可以连接信号
    //2.一个信号可以连接多个槽函数
    //3.多个信号可以连接同一个槽函数
    //4.信号和槽函数的参数必须类型一一对应
    //5.信号和槽的参数个数  是否要一致？信号的参数个数可以多于槽函数的参数个数


    //lambda表达式的mutable用于修改值传递的变量，修改的是拷贝而不是本体。加了mutable就能修改，不加就是只读
    //lambda表达式最常用：[=](){}
    //QPushButton*btn2=new QPushButton;

    // [btn](){
    //     btn->setText("aaaa");
    //     btn2->setText("bbb");//btn2看不到
    // }();

    //利用lambda表达式 实现点击按钮关闭窗口
    QPushButton* btn2=new QPushButton;
    btn2->setText("关闭");
    btn2->move(100,0);
    btn2->setParent(this);
    connect(btn2,&QPushButton::clicked,this,[=](){
        // this->close();
        // emit zt->hungry("宫保鸡丁");

        btn2->setText("aaa");
    });

}


void Widget::classIsOver()
{
    //下课函数，调用后出发老师饿了的信号
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}
