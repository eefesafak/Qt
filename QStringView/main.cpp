#include <QCoreApplication>

void readname(QString name)// address of is access of
{
    name.insert(0, "Mr.");
    qInfo() << "Changed: " << name;

}

void readonly(QStringView name)
{
    qInfo() << "name: " << name.data() << name;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstname = "Efe";
    QString lastname = "Safak";

    //copy and modification issues
    readname(firstname);
    qInfo() << "Original: " << firstname;

    //read only, no copy
    qInfo() << "name: " << firstname.data() << firstname;
    readonly(firstname);

    //basic parsing
    QString fullname = firstname + " " + lastname;

    foreach(QStringView part, QStringView(fullname).split(QChar(' ')))
    {
        qInfo() << "part" << part;
        if(part.startsWith(QStringView(firstname), Qt::CaseInsensitive))
        {
            qInfo() << "~First name detected~";
            readonly(QStringView(firstname).mid(1, 3));
        }
    }


    return a.exec();
}
