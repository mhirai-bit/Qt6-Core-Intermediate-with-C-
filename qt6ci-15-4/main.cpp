#include <QCoreApplication>
#include <QProcess>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess proc;
    proc.start("Excel");
    QTimer::singleShot(3000, &proc, &QProcess::terminate);


    return a.exec();
}
