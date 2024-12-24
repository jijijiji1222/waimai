#include "student.h"
#include <QDebug>
Student::Student(QObject *parent)
    : QObject{parent}
{}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    //QString->char *的方法
    //通过.toUtf8()转成QByteArray，再用.data()转成char *
    //可以消除双引号
    qDebug()<<"请老师吃饭，老师要吃："<<foodName.toUtf8().data();
}
