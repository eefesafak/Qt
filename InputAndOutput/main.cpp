#include <QCoreApplication>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QTextStream
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    // endl
    qout << "Please enter your name:" << Qt::endl;

    // reading
    QString name = qin.readLine();

    //flushing
    qout << "You entered: " << name << "\n";
    qout << "Enter your age: \n";
    qout.flush();

    //example
    bool ok;
    int age = qin.readLine().toInt(&ok);

    if(ok)
    {
        qout << "You are " << age << " years old";
    }

    else{
        qout << "You have failed to enter a valid number!!" << Qt::endl;
    }
    qout.flush();

    return a.exec();

}
