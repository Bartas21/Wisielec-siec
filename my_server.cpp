#include "my_server.h"

//#include <password_maker.h>


my_server::my_server(QObject *parent) :
    QTcpServer(parent)
//    QObject(parent)
{
//    server = new QTcpServer(this);

//    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

//    if(!server->listen(QHostAddress::Any, 1000))
//    {
//        qDebug() << "Server could not start!";
//    }
//    else
//    {
//        qDebug() << "Server started!";

//    }
}

void my_server::StartServer() //obsługa połączenia
{
    if(!this->listen(QHostAddress::Any,1000))//&&(!this->listen(QHostAddress::Any,1001)))
        {
            qDebug() << "Could not start server";
        }
        else
        {
            qDebug() << "Listening...";
    }
}

void my_server::incomingConnection(int socketDescriptor) //uruchamia sie przy dodaniu kazdego gracza, kazde połączenie ma nowy wątek
{
    qDebug() << socketDescriptor << " Connecting...";
    Thread *thread = new Thread(scores, socketDescriptor, this); //wątek
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}



//void my_server::newConnection()
//{
//    QTcpSocket *socket = server->nextPendingConnection();


//    //????????????????????????
//        password_maker manager;

//    socket->waitForBytesWritten(3000);

//    while(socket->waitForReadyRead())
//    {
//        QString a;
//        QByteArray array = socket->readAll();
//        char* buffer = array.data();
//        if(buffer[0]=='#')
//        {
//            manager.new_password();
//            a=QString::fromStdString(manager.flor_table);
//        }
//        else if (buffer[0]=='=') {
//            a=manager.pic();
//        }
//        else
//        {
//            manager.chek(buffer[0]);
//            a=QString::fromStdString(manager.flor_table);
//        }

//        socket->write(a.toLocal8Bit());

//    }
//    socket->close();
//}
