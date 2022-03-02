#include <QCoreApplication>
#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Person person(&a, QString("taro"), QString("todai"));
    qInfo() << person.display();

    return a.exec();
}
