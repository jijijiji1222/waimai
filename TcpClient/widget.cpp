#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket=new QTcpSocket;//创建
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_cancelButton_clicked()
{
    this->close();
}


void Widget::on_pushButton_2_clicked()
{
    //获取IP地址和端口号
    QString IP = ui->ipLineEdit->text();
    QString port=ui->portLineEdit->text();

    // qDebug<<IP;
    // QDebug<<port;

    //连接服务器
    socket->connectToHost(QHostAddress (IP),port.toShort());

    //连接服务器成功，socket对象会发出信号
    connect(socket,&QTcpSocket::connected,[this]()
    {
        QMessageBox::information(this,"连接提示","连接服务器成功");
    });


    //连接异常，socket也会发出信号
    connect(socket,&QTcpSocket::disconnected,[this]()
            {
        QMessageBox::warning(this,"连接断开","连接异常，网络断开");
    });
}

