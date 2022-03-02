#include <QCoreApplication>
#include <QByteArray>
#include <QByteArrayView>

void display(QByteArrayView &view)
{
    qInfo() << view;
    for(auto c: view)
    {
        qInfo() << c;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QByteArray bytes("Hello world how are you?");
    QByteArrayView view(bytes);

    display(view);
    return a.exec();
}
