#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //槽函数写到这里
    //返回值void，需要声明，也需要实现
    //可以有参数，可以重载
    void treat();

    void treat(QString foodName);

signals:
};

#endif // STUDENT_H
