#include "testnet_c.h"
#include "ui_testnet_c.h"

testnet_c::testnet_c(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testnet_c)
{
    ui->setupUi(this);
    this->connect(ui->pushButton_con,SIGNAL(clicked()),this,SLOT(connectServer()));

    this->connect(ui->pushButton_send,SIGNAL(clicked()),this,SLOT(sendMesg()));

}
testnet_c::~testnet_c()
{
    delete ui;
}
void testnet_c::connectServer()
{
    qDebug() << "dd";

    m_tcpSocket = new QTcpSocket(this);
    m_tcpSocket->abort();

    m_tcpSocket->connectToHost("127.0.0.1",19999);
    connect(m_tcpSocket,SIGNAL(readyRead()),this,SLOT(readMesg()));
}
void testnet_c::readMesg() //读取信息
{
    QByteArray qba = m_tcpSocket->readAll();
    ui->textEdit_recmesg->clear();
    qDebug()<<qba;
    QString ss=QVariant(qba).toString();
    ui->textEdit_recmesg->setText(ss);
}
void testnet_c::sendMesg() //发送信息
{
    qDebug() << "sendMesg()";
    QString ss= ui->lineEdit_sendmesg->text();
    qDebug() << ss;
    m_tcpSocket->write(ss.toStdString().c_str(),strlen(ss.toStdString().c_str()));
    ui->lineEdit_sendmesg->clear();
}
