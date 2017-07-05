#ifndef TESTNET_C_H
#define TESTNET_C_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class testnet_c;
}

class testnet_c : public QMainWindow
{
    Q_OBJECT

private slots:
    void connectServer();
    void sendMesg();
    void readMesg();

public:
    explicit testnet_c(QWidget *parent = 0);
    ~testnet_c();

private:
    Ui::testnet_c *ui;
    QTcpSocket *m_tcpSocket;
};

#endif // TESTNET_C_H
