#include <QCoreApplication>
#include <QMap>
#include <QSharedPointer>
#include "test.h"

typedef QMap<QString, QSharedPointer<Test>> Testmap;

void testMapAuto()
{
    Testmap map;

    for(int i = 0; i < 5; i++)
    {
        QString id = "ID-" + QString::number(i);
        QString name = "Item-" + QString::number(i);
        QSharedPointer<Test> ptr(new Test(nullptr, name));
        map.insert(id, ptr);
    }

    foreach(QString key, map.keys())
    {
        qInfo() << key << map[key].data();
    }

    map.clear();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testMapAuto();
    return a.exec();
}
