#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "Bryan" << "Tammy" << "Chris" << "Heather";
    people.insert("Rango");

    foreach(QString person, people)
    {
        qInfo() << person;
    }

    qInfo() << "Bryan in colection?" << people.contains("Bryan");

    return a.exec();
}
