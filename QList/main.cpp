#include <QCoreApplication>
#include <QSharedPointer>
#include <QRandomGenerator>

// creating and adding data

QList <int> getNumbers()
{
    QList <int> list;

    //use the operator
    list << 300 << 400 << 500;

    int max = QRandomGenerator::global()->bounded(1,10);
    for(int i = 0; i<max; i++){
        list.append(QRandomGenerator::global()->bounded(1, 100));
    }
    return list;
}

void test_numbers() {
    QList <int> list = getNumbers();
    qInfo() << list;

    qInfo() << "Length: " << list.length(); // same
    qInfo() << "Count" << list.count(); // same
    qInfo() << "Size" << list.size(); // same

    for(int i=0; i<list.length(); i++){
        qInfo() << i << "=" << list.at(i) << "or" << list[i];
    }

    qInfo() << "---------";
    foreach(int i, list){
        qInfo() <<i;
    }
}

//searching
void test_search() {
    QList <int> list = getNumbers();
    int item = 999;

    qInfo() << "---------";
    list.insert(0, item);
    list.insert(3, item);
    list.append(item);

    for(int i = 0; i<list.length();i++){
        qInfo() << i << "=" << list.at(i);
    }

    //first
    int fpos = list.indexOf(item);
    qInfo() << "First" << fpos;

    //last
    int lpos = list.lastIndexOf(item);
    qInfo() << "Last" << lpos;

    //all
    int pos = list.indexOf(item);
    do{
        qInfo() << "At" << pos;
        pos = list.indexOf(item, pos + 1);
    }while(pos > -1);

    qInfo() << "Contains" << list.contains(item);

    //get a slice
    QList<int> items = list.sliced(1, 3);
    qInfo() << list;
    qInfo() << items;
}

// modifying existing data
void test_modifying() {
    QList<int> list = getNumbers();

    //direct mod
    list[0] = 1000;

    //appending
    list.append(99);
    list << 20000 << 30000;

    //inserting
    list.insert(0, 55);
    list.insert(1, 22);
    list.insert(1, 255);
    list.insert(1, 255);
    list.insert(1, 255);
    list.insert(1, 255);
    list.insert(1, 255);
    list.insert(1, 255);
    list.insert(1, 255);

    // removing
    qInfo() << "Length" << list.length();
    list.removeAt(0);
    qInfo() << "removeAt = " << list.length();
    list.removeOne(255);
    qInfo() << "removeOne = " << list.length();
    list.removeAll(255);
    qInfo() << "removeAll" << list.length();
    list.remove(2,3);
    qInfo() << "remove: " << list.length();

    for(int i = 0; i < list.length(); i++){
        qInfo() << i << "=" << list.at(i);
    }
}

int main (int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    // creating and adding data
    //test_numbers();

    //modifying existing data
    //test_modifying();
    test_search();

    return a.exec();
}
