#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QLockFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath() + QDir::separator() + "text.txt";
    QFile file(path);
    QLockFile lock(file.fileName() + "l");
    lock.setStaleLockTime(3000);

    if(lock.tryLock())
    {
        qInfo() << "Putting into file...";
        if(file.open(QIODevice::WriteOnly)){
            QByteArray data;
            file.write(data);
            file.close();
            qInfo() << "Finished with file...";
            //Took over 3 seconds here, auto unlock
        }
        qInfo() << "Unlocking file";
        lock.unlock();
    }
    else{
        qInfo() << "File is locked, but we can't get the info!";
    }

    return a.exec();
}
