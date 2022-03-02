#include <QCoreApplication>
#include <QSharedPointer>
#include "test.h"

void testListAuto()
{
    QList<QSharedPointer<Test>> list;
    for(int i = 0; i < 5; i++)
    {
        QSharedPointer<Test> item(new Test(nullptr, "Item" + QString::number(i)));
        list.append(item);
    }

    foreach(QSharedPointer<Test> test, list)
    {
        qInfo() << test.data();
    }

    qInfo() << "Remove one item";
    list.removeAt(0);
    foreach(QSharedPointer<Test> test, list)
    {
        qInfo() << test.data();
    }
    qInfo() << "Clearing";
    list.clear();
    foreach(QSharedPointer<Test> test, list)
    {
        qInfo() << test.data();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testListAuto();

    return a.exec();
}
