#include <QCoreApplication>
#include <QVector>
#include <iostream>
using namespace std;

QVector<QString> vectorCall() {
    QVector<QString> vector;
    vector.append("one");
    vector.append("two");
    QString three = "three";
    vector.append(std::move(three));
    qInfo() << vector << Qt::endl << "three:" << three;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QVector that stores integers and QString values..
    QVector<int> integerVector;
    QVector<QString> stringVector;
    qInfo() << integerVector;
    qInfo() << stringVector;

    //QVector with 5 elements
    QVector<QString> vector(5);
    qInfo() << vector;

    QVector<QString> vector1(5, "efe");
    qInfo() << vector1;
    vector1.fill("a");
    qInfo() << vector1;

    if(vector1[0] == "a" && vector1[1] == "a"){
        qInfo() << "Helloooo";
    }

    vector1.fill("Alfonso");
    // for read-only access, an alternative syntax is to use at()
    for(int i = 0; i<vector1.size(); i++){
        if(vector1.at(i) == "Alfonso"){
            cout << "Found Alfonso at position " << i << endl;
        }
    }

    vector1<< "Harumi" << "Efe";
    qInfo() << vector1;
    int i = vector1.indexOf("Harumi");
    if (i != -1)
        qInfo() << "First occurence of Harumi is at position" << i << Qt::endl;

    //insert value at index position
    QVector<QString> vectorr;
    vectorr << "alpha" << "beta" << "delta";
    vectorr.insert(2, "gamma");
    qInfo() << "Insert gamma" << vectorr << Qt::endl;

    vector.clear();
    qInfo() << vectorr;

    //insert value at the beginning of the vector
    vector.prepend("one");
    vector.prepend("two");
    vector.prepend("three");
    qInfo() << "vector: " << vector << Qt::endl;
    vector.clear();
  
    //inserts value at the end of the vector
    vector.append("three");
    vector.append("two");
    QString name = "one";
    vector.append(name);
    qInfo() << "Vektör:" << vector << Qt::endl;

    // returns a pointer to the data stored in the vector
    QVector<int> vector2(10);
    int *data = vector2.data();
    for(int i = 0; i<10;i++){
        data[i] = 2*i;
    } qInfo() << vector2;

    // return a QVector from list
    QStringList list;
    list << "Sven" << "Kim" << "Ola";
    QVector<QString> vect = QVector<QString>::fromList(list);
    qInfo() << "vect:" << vect;

    //indexOf
    QVector<QString> vector3;
    vector3 << "A" << "B" << "C" << "B" << "A";
    qInfo() << vector3.indexOf("B"); // 1
    qInfo() << vector3.indexOf("B", 2); // 3
    qInfo() << vector3.indexOf("X");
    
    QVector<double> vector4;
    vector4 << 2.718 << 1.442 << 0.4342;
    vector4.insert(1, 3, 9.9);
    qInfo() << vector4;
    
    //QVector to QList
    
    QVector<QString> vect1;
    vect1 << "red" << "green" << "blue" << "black";
    
    QList<QString> list2 = vect1.toList();
    qInfo() << list2; 

   
    return a.exec();
}
