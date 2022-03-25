#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include "test.h"

// setting in the constructor
Test* getTest(QObject* parent){
    return new Test(parent);
}

// setting up after the constructor
Test* getTest(){
    return new Test(); // no parents
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.singleShot(3000, &a, &QCoreApplication::quit);

    // setting in the constructor
    Test* dog = getTest(&a);
    dog->setObjectName("Karabas");

    //setting up after the constructor
    Test* cat = getTest(&a);
    cat->setObjectName("Pamuk");
    cat->setParent(dog);

    int value = a.exec();
    qInfo()<< "Exit code: " << value<<Qt::endl;
    return value;

}
