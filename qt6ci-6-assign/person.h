#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDebug>
#include <QStringView>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr, QString firstname = "", QString lastname = "");

    QStringView display();
    ~Person();

signals:

private:
    QString m_firstname;
    QString m_lastname;

};

#endif // PERSON_H
