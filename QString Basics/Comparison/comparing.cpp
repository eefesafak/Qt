#include <QString>
#include <QCoreApplication>
#include <QTextStream>
#define STR_EQUAL 0
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);

    QString aa = "Rain";
    QString b = "rain";
    QString c = "rain\n";

    if(QString::compare(aa, b) == STR_EQUAL)
    {
        out << "a, b are equal" << Qt::endl;
    } else{
        out << "a, b are not equal" << Qt::endl;
    }
    out << "In case insensitive comparison:" << Qt::endl;

    if(QString::compare(aa, b, Qt::CaseInsensitive) == STR_EQUAL){
        out << "a, b are equal" << Qt::endl;
    }else{
        out << "a, b are not equal" << Qt::endl;
    }

    if (QString::compare(b, c) == STR_EQUAL){
        out << "b, c are equal" << Qt::endl;
    }else{
        out << "b, c are not equal" << Qt::endl;
    }

    //removes n characters from end of the string
    c.chop(1);

    out << "After removing the new line character" << Qt::endl;

    if(QString::compare(b, c) == STR_EQUAL)
    {
        out << "b, c are equal" << Qt::endl;
    }else{
        out << "b, c are not equal" << Qt::endl;
    }

    return a.exec();
}
