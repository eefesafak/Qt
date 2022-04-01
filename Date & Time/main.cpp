#include <QString>
#include <QCoreApplication>
#include <QTextStream>
#include <QDate>
#include <QTime>
#define STR_EQUAL 0
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);

    QDate dt1(2015, 4, 12);
    out << "The date is " << dt1.toString() << Qt::endl;

    QDate dt2;
    dt2.setDate(2000, 8, 1);
    out << "The date is " << dt2.toString() << Qt::endl;

    QTime tm1(17, 30, 12, 55);
    out << "The time is " << tm1.toString("hh:mm:ss.zzz") << Qt::endl;

    QTime tm2;
    tm2.setHMS(13, 52, 45, 155);
    out << "The time is " << tm2.toString("hh:mm:ss.zzz") << Qt::endl;


    return a.exec();
}
