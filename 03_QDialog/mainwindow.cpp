#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮，弹出一个对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框分类
        //模态对话框（不可以） 非模态对话框（可以对其他窗口进行操作）
        //模态创建  阻塞
        // QDialog dlg(this);
        // dlg.resize(200,100);
        // dlg.exec();

        // qDebug()<<"模态对话框弹出了";

        //非模态对话框
        QDialog *dlg2=new QDialog (this);
        dlg2->resize(200,100);
        dlg2->show();
        dlg2->setAttribute(Qt::WA_DeleteOnClose);//55号属性，防止new太多爆掉
        qDebug()<<"非模态对话框弹出了";

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
