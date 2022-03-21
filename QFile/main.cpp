#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>
void Write(QString Filename){
    QFile mFile(Filename);

    if(!mFile.open(QFile::WriteOnly | QFile:: Text)){
        qDebug() << "Could not open file for writing";
        return ;
    }

    QTextStream out(&mFile);
    out << "Hello World";
    mFile.flush();
    mFile.close();
}

void Read(QString Filename){
    QFile mFile(Filename);

    if(!mFile.open(QFile::ReadOnly | QFile:: Text)){
        qDebug() << "Could not open file for reading";
        return ;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;

    in << "Hello World";

    mFile.close();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString mFilename = "/home/efe/denemee.txt";
    Write(mFilename);
    Read(mFilename);

    return a.exec();
}
