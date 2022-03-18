#include <iostream>

#include <QCoreApplication>

using namespace std;

void test(QString data)
{
 qInfo() << data;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString line("Hello World");
    qInfo() << line;

    QString name = "Efe Safak";
    qInfo() << name;

    int pos = 504;
    int max = 10000;

    QString status = QString("Processing file %1 of %2").arg(pos).arg(max);
    qInfo() << status;

    // reading each char

    for(int i=0;i<line.length(); i++)
    {
        QChar c = line.at(i);
        qInfo() << c;
    }

    // comparing and searching
    qInfo() << "Compare" << line.compare("hello world", Qt::CaseSensitivity::CaseSensitive);
    qInfo() << "Starts" << line.startsWith("hello", Qt::CaseInsensitive);
    qInfo() << "Ends" << line.endsWith("world", Qt::CaseSensitivity::CaseInsensitive);
    qInfo() << "Contains" << line.contains("world", Qt::CaseInsensitive);
    qInfo() << "Index" << line.indexOf("World");

    // modifying and parsing
    line.append("\r\nhow are you?");
    qInfo() << "Escape" <<line;

    line.append("\r\n<i>this</i> HTML <br>");
    qInfo() <<"Html"<<line.toHtmlEscaped();

    line.replace("?", "!");
    qInfo() << "Replaced" << line;

    qInfo() << "Upper" << line.toUpper();
    qInfo() << "Lower" << line.toLower();
    qInfo() << "Mid" << line.mid(3, 5).toLower();

    qInfo() << "Line: " <<line;

    QStringList list = line.split("\n");
    foreach(QString item, list)
    {
        qInfo() << "item" << item.trimmed();
    }

    //conversion
    std::cout << "std " << line.toStdString() << std::endl;

    qInfo() << "UTF8" <<line.toUtf8(); // byte array
    qInfo() <<"Base64" << line.toUtf8().toBase64();
    qInfo() << "Hex" << line.toUtf8().toHex();

    // not a QObject
    test(line);

    return a.exec();
}
