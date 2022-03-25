#include "mythread.h"
#include <QtCore>
#include <QDebug>

MyThread::MyThread()
{

}
void MyThread::run(){
    qDebug() << this->name << " Running";

    for(int i = 0; i < 1000; i++){
        QMutex mutex;
        mutex.lock();
        if(this->stop){
            break;
        }
        mutex.unlock();
        this->sleep(1);

        qDebug() << this->name << i;
    }

}
