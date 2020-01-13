#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include "thread.h"
//#include <password_maker.h>

#include <vector>

class my_server : public QTcpServer//QObject
{
    Q_OBJECT
public:
    explicit my_server(QObject *parent = 0);
    void StartServer();
    int scores[2]= {0,0};

signals:

public slots:
//    void newConnection();


protected:
    void incomingConnection(int socketDescriptor); //literki przed połączeniem

//private:
//    QTcpServer *server;
};

#endif // SERVER_H
