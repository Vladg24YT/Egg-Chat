#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // подключение к серверу
    socket = new QTcpSocket(this);
    socket->connectToHost("95.165.152.146", 34197);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// отправка строки из поля на сервер
void MainWindow::sendToServer(QString str)
{
    data.clear();
    data = QByteArray::fromStdString(str.toStdString());

    socket->write(data);
    //ui->textBrowser->append("sended: " + data); // для отладки
}

void MainWindow::slotRead()
{
    // чтение сокета
    while(socket->bytesAvailable() > 0)
        {
            ui->textBrowser->append(socket->readAll());

        }

}

// реакция на нажатие кнопки
void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    sendToServer(str);
    ui->lineEdit->clear();
}

// на нажатие Enter
void MainWindow::on_lineEdit_returnPressed()
{
    sendToServer(ui->lineEdit->text());
    ui->lineEdit->clear();
}

