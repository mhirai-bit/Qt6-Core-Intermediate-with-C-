#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> v;
    v << 1 << 2 << 3;

    qInfo() << v;

    foreach(int i, v)
    {
        qInfo() << i;
    }

    return a.exec();
}
