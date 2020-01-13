// thread.cpp

#include "thread.h"

#include "password_maker.h"

Thread::Thread(int *t, int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
    tab=t;
}

void Thread::run()
{
    // thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop
    exec();
}

void Thread::readyRead()
{
//    QByteArray Data = socket->readAll();

//    qDebug() << socketDescriptor << " Data in: " << Data;

//    socket->write(Data);
    password_maker manager;
    while(socket->waitForReadyRead())
    {
        QString a;
        QByteArray array = socket->readAll();
        char* buffer = array.data();
        if(buffer[0]=='#') //reset
        {
            manager.new_password();
            a=QString::fromStdString(manager.flor_table);
        }
        else if (buffer[0]=='=') {
            a=manager.pic();
        }
        else if (buffer[0]=='*') {
            a=manager.pkt();
        }
        else if (buffer[0]=='1') {//pierwszy pyta
            a=QString::number(tab[1]);//dostaje info o drugim
            tab[0]=manager.p;//aktualizuje info o pierwszym
        }
        else if (buffer[0]=='2') {//drugi pyta
            a=QString::number(tab[0]);
            tab[1]=manager.p;
        }
        else
        {
            manager.chek(buffer[0]); //sprawdzenie liter
            a=QString::fromStdString(manager.flor_table);
        }

        socket->write(a.toLocal8Bit());
//        socket->flush();

    }
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}
