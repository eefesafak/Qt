#include <QCoreApplication>

void stats(QByteArray &data)
{
    qInfo() << "Length" << data.length() << "Capacity" << data.capacity();
    qInfo() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // creating an array
    QByteArray stuff;
    qInfo() << stuff; //qInfo() treats like it's a string

    QByteArray data("Hello");
    qInfo() << data; // "Hello"

    QByteArray buffer(10, '\t');
    qInfo() << buffer; // "\t\t\t\t\t\t\t\t\t\t"

    QByteArray person(QString("Efe").toLocal8Bit());
    qInfo() << person; // "Efe"

    //sizing the array
    data.reserve(25); // Length 5 Capacity 25
    stats(data); // "Hello"

    data.resize(10); // length 10 capacity 25,,,, resize is prefered
    stats(data); // "Hello\x00\x00\x00\x00\x00"

    data.truncate(8); // length 8 capacity 25
    stats(data); // "Hello\x00\x00\x00"

    data.clear(); // Length 0 Capacity 0
    stats(data); // ""

    //modifying data

    data.resize(5);
    data.fill('\x02'); //Length 5 Capacity 16
    stats(data); //"\x02\x02\x02\x02\x02"

    data.replace(0, 99, QByteArray("Sweet"));
    stats(data);

    data.fill('*');
    data.insert(3, QByteArray("Hello World"));
    stats(data);

    data.append('!');
    stats(data);

    data.remove(0, 3);
    stats(data);


    // reading data
    int first = data.indexOf('*');
    int last = data.lastIndexOf('*');
    qInfo() << "Start" << first << "End" << last;

    if(first > -1 && last > -1)
        qInfo() << data.mid(first, (last - first) +1);

    data.clear();
    data.append("Efe Safak");

    for(int i=0; i<data.length();i++){
        qInfo() << "At" << data.at(i) << "or" << data[i];
    }

    foreach(char c, data)
    {
        qInfo() << "Char" << c;
    }

    foreach(auto item, data.split(' '))
    {
        qInfo() << "Item" << item;
    }

    //encoding the data
    qInfo() << "Normal" << data;
    qInfo() << "Repeat" << data.repeated(3);

    data.append(QByteArray("\t\r\n"));
    data.insert(0, QByteArray("        \t\t\t"));
    qInfo() << "Trimmed" <<data.trimmed();
    qInfo() << "Actual" << data;
    data = data.trimmed();
    qInfo() << "Actual" << data;

    QByteArray hex = data.toHex();
    qInfo() << "Hex" << hex;
    QByteArray from_hex = QByteArray::fromHex(hex);
    qInfo() << "From Hex" << from_hex;

    QByteArray base64 = data.toBase64();
    qInfo() << "base64" << base64;
    QByteArray from_base64 = QByteArray::fromBase64(base64);
    qInfo() << "From base64" << from_base64;

    return a.exec();
}
