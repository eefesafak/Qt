#include <QString>
#include <QCoreApplication>
#include <QTextStream>
#define STR_EQUAL 0
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);

    int digits = 0;
    int letters = 0;
    int spaces = 0;
    int puncts = 0;

    QString str = "7 white, 3 red roses.";

    foreach(QChar s, str)
    {
        if(s.isDigit()){
            out << "isDigit: " << s << " ";
            digits++;
        }else if (s.isLetter()){
            out<< "isLetter: " << s << " ";
            letters++;
        }else if(s.isSpace()){
            out<< "isSpace: " << s << " ";
            spaces++;
        }else if (s.isPunct()){
            out<< "isPunct: " << s << " ";
            puncts++;
        }
        out<< Qt::endl;
    }

    out << QString("There are %1 characters").arg(str.count()) << Qt::endl;
    out << QString("There are %1 letters").arg(letters) << Qt::endl;
    out << QString("There are %1 digits").arg(digits) << Qt::endl;
    out << QString("There are %1 spaces").arg(spaces) << Qt::endl;
    out << QString("There are %1 punctional characters.").arg(puncts) << Qt::endl;

    return a.exec();
}
