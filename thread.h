#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(int *t, int iID, QObject *parent = 0);
    void run();
    int *tab; //wskaźnik na punkty

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

public slots:

private:
    QTcpSocket *socket; //wskaźnik na socket
    int socketDescriptor;

};

#endif // THREAD_H
