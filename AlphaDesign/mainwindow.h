#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QDir>
#include <QFile>
#include <QObject>
#include <QTcpSocket>
#include <vector>
//#include <QtTest/QTest>


#include "chat.h"
#include "invite.h"


class server;
class MainWindow;

/*!
 * \brief The destroyer class
 * Деструктор для класса server
 */
class destroyer{
private:
    server * p_instance;
public:
    ~destroyer() {delete p_instance;}
    /*!
     * \brief init
     * Инициализирует этот класс указанием ссылки на класс server
     * \param [server*]p указатель на класс server
     */
    void init(server * p){ p_instance = p; };
};

/*!
 * \brief Класс сервера по паттерну SingleTon
 */
class server : public QObject{
    Q_OBJECT
private:
    bool connected = false;
    static server * p_instance;
    static destroyer destro;
    QTcpSocket * socket;

protected:
    /*!
     * \brief server
     * Конструктор по умолчанию
     * \param parent
     * Родитель
     */
    explicit server(QObject * parent = nullptr);
    server(const server&) = delete;
    server& operator = (server &) = delete;
    //~server();
    friend class destroyer;
    friend class MainWindow;
    /*!
     * \brief ptr
     * Ссылка экземпляр класса MainWindow <br>
     * для удобного общения с ним
     */
    MainWindow * ptr;
    /*!
     * \brief parser
     * Парсит строку по |
     * \param [QString]line
     * Берет строку на вход
     */
    void parser(QString line);
public:
    /*!
     * \brief getInstance
     * Возвращает ссылку на себя
     * \return
     * [Server*] - ссылка на себя
     */
    static server * getInstance();
    //void signIn(QString login, QString password);
private slots:
    void readSocket();
};



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class
 * Класс окна, в котором происходит
 * <br> всё взаимодействие с пользователем
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class server;
    bool mode = true; // false - login, true - reg
    bool emailChange = true, loginChange = true,
         passChange = true, newChatCreate = true, // false - chatting, true - creating new chat
         invNewUserMode = true,
         loginedUser = false; // вошел ли юзер в аккаунт
    void sendToServer(QString);

public:
    /*!
     * \brief MainWindow
     * Конструктор класса окна
     * <br> Вызывается в main.cpp
     * \param [QWidget]parent ???
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_changeModeButton_clicked();
    void on_SignButton_clicked();
    void on_ChangePassBtn_clicked();
    void on_ChangeEmailBtn_clicked();
    void on_changeLoginBtn_clicked();
    void on_checkBox_2_stateChanged(int arg1);
    void on_logoutBtn_clicked();
    void on_listWidget_itemSelectionChanged();
    void on_pushButton_clicked();
    void on_CreateNewChat_clicked();
    void on_InviteUserBtn_clicked();
    void on_leaveChatBtn_clicked();
    void on_InvUserBtn_clicked();
    void on_ChatLine_returnPressed();
    void on_tabWidget_currentChanged(int index);
    void on_InviteAccept_clicked();
    void on_InviteDecline_clicked();

private:
    QString homeDir;
    QMap<QString, chat> chats;
    QMap<QString, invite> invites;
    QString currentChat;

    void readData();
    void writeData(int stat);

    void changeMode();
    void changePassMode();
    void changeEmailMode();
    void changeLoginMode();
    void changeChatMode();
    void changeInvUserMode();
    void changeAccountStatus(bool newStatus);
    void changeConnectStat(bool setTo);
    void createNewChat();
    void setLoginTabEnable(bool setTo);

    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
