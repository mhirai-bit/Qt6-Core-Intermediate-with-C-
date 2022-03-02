#include "person.h"

Person::Person(QObject *parent, QString firstname, QString lastname)
    : QObject{parent},
      m_firstname{firstname},
      m_lastname{lastname}
{
    qInfo() << this << " is constructed with a name : " << m_firstname << " " << m_lastname;
}

QStringView Person::display()
{
    return QStringView(m_firstname + " " + m_lastname);
}

Person::~Person()
{
    qInfo() << this << " is destructed with a name :" << m_firstname << " " << m_lastname;
}
