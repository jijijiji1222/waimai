#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionnew->setIcon(QIcon("C:/Users/Lenovo/Pictures/Screenshots/screenshot1.png"));

    //使用添加Qt资源  ":+前缀名+文件名"（似乎只能用png格式）
    ui->actionnew->setIcon(QIcon(":/C:/Users/Lenovo/Desktop/logo/OIP (1).png"));
    ui->actionopen->setIcon(QIcon(":/C:/Users/Lenovo/Desktop/logo/OIP (2).png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
