#include <QCoreApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    //Easy append
    list << 1 << 2 << 3;

    for(int i = 0; i < 5; i++)
    {
        list.append(i);
    }

    qInfo() << list;

    qInfo() << "length" << list.length();
    qInfo() << "Size" << list.size();
    qInfo() << "Count" << list.count();
    qInfo() << "Count" << list.count(3);

    list.replace(2, 99);
    list << 3 << 3 << 3;
    qInfo() << list;
    list.remove(3);
    qInfo() << list;

    foreach(int i, list)
    {
        qInfo() << i;
    }

    list.removeAll(3);

    for(int i =0; i < list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i);
    }

    QList<int> slice = list.sliced(2,3);

    qInfo() << "Slice " << slice;
    qInfo() << "List" << list;
    qInfo() << "Contains " << list.contains(6);
    qInfo() << "Indexof " << list.indexOf(6);
    list.clear();

    qInfo() << "Length " << list.length();
    qInfo() << "Size" << list.size();
    qInfo() << "Count" << list.count();

    return a.exec();
}
