#include <QCoreApplication>
#include <QSettings>
#include <QTextStream>
#include <iostream>

void saveName(QSettings *setting, QString name)
{
    setting->setValue("1", name);
}

bool getName(QSettings *setting, QString &name)
{

    name = setting->value("1", QVariant("does not exist")).toString();
    if(name == "does not exist")
    {
        return false;
    }else{
        return true;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString filename = a.applicationDirPath() + "/settings.ini";
    QSettings settings(filename, QSettings::Format::IniFormat);

    QString line = nullptr;
    if(getName(&settings, line))
    {
        qInfo() << "Hello: " << line;
    }
    else{
        qInfo() << "Please type your name :";
        QTextStream stream(stdin);
        do
        {
            line = stream.readLine();
        }while(line == nullptr);
        saveName(&settings, line);
        qInfo() << "Name is saved";
    }





    return a.exec();
}
