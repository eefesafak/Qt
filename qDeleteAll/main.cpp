#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "test.h"

// get a list of poiners
typedef QList<Test*> testList;

testList getList(){
    testList list;
    for(int i = 0; i<5; i++){
        list.append(new Test());
        list.last()->setObjectName("Test " + QString::number(i));
    }
    return list;
}

// display a list of pointers
void display(testList list){
    foreach(Test* item, list){
        qInfo() << item;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testList list = getList();
    display(list);

    qInfo() << "Deleting..."<< Qt::endl;
    //qDeleteAll(list); //the entire list
    qDeleteAll(list.begin(), list.end());
    list.clear();

    display(list);


    return a.exec();























}
