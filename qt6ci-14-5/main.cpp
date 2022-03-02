#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

bool test()
{
    QProcess zip;
    zip.start("7zip");
    if(!zip.waitForStarted(3000)) return false;

    QByteArray data;
    for(int i = 0; i < 100; i++)
    {
        QString item = "Item " + QString::number(i);
        data.append(item.toUtf8());
    }

    zip.write(data);
    zip.closeWriteChannel();
    if(!zip.waitForFinished(3000)) return false;

    QByteArray result = zip.readAll();

    qInfo() << "Before: " << data.size();
    qInfo() << "Result: " << result.size();
    qInfo() << "Compressed: " << result;

    return true;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if(test())
    {

    }

    qInfo() << "end";



    return a.exec();
}
