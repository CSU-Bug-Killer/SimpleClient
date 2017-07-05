#include "testnet_c.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testnet_c w;
    w.show();

    return a.exec();
}
