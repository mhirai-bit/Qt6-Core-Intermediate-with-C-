#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr);
    ~Consumer();
    void consume(int value);

signals:

};

#endif // CONSUMER_H
