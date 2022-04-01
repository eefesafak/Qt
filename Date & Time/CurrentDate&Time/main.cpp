#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    out << "Current date is: " << cd.toString() << Qt::endl;
    out << "Current time is: " << ct.toString() << Qt::endl;


    return a.exec();
}
