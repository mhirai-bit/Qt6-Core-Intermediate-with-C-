#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void timeout();
    void dostuff();

private:
    QTimer timer;
    int number;

};

#endif // TEST_H
