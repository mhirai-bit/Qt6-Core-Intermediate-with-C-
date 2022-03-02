#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(network);
Q_LOGGING_CATEGORY(network, "network");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "test";

    qInfo(network) << "test";
    qWarning(network) << "test";

    QLoggingCategory::setFilterRules("network.debug=false");

    qDebug(network) << "kitty";
    qDebug() << "kitty1";
    if(!network().isDebugEnabled())
    {
        QLoggingCategory::setFilterRules("network.debug=true");
        qDebug(network) << "kitty";
    }

    return a.exec();
}
