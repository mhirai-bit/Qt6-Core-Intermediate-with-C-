#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{

}

void Test::testing()
{
    qWarning() << "This is a test!!!";
}
