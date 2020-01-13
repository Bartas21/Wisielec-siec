#include <QCoreApplication>
#include "my_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    my_server dzialaj;
    dzialaj.StartServer();

    return a.exec();
}
