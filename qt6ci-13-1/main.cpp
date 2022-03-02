#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include "test.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<Test*> list;
    for(int i = 0; i < 10; i++)
    {
        Test *t = new Test(); //no parent, no smart pointer
        t->setObjectName(QString::number(i));
        list.append(t);
    }

    qInfo() << list.at(0);

    qDeleteAll(list);
    list.clear();

    return a.exec();
}
