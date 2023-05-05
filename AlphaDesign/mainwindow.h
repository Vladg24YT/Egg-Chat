#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QDir>
#include <QFile>
#include <QObject>
#include <QTcpSocket>
#include <vector>


#include "chat.h"
#include "invite.h"

class server;
class MainWindow;

class destroyer{
private:
    server * p_instance;
public:
    ~destroyer() {delete p_instance;}
    void init(server * p){ p_instance = p; };
};

class server : public QObject{
    Q_OBJECT
private:
    static server * p_instance;
    static destroyer destro;
    QTcpSocket * socket;

protected:
    explicit server(QObject * parent = nullptr);
    server(const server&) = delete;
    server& operator = (server &) = delete;
    //~server();
    friend class destroyer;
    friend class MainWindow;
    MainWindow * ptr;
    void parser(QString line);
public:
    static server * getInstance();
    void signIn(QString login, QString password);
private slots:
    void readSocket();
};



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class server;
    bool mode = true; // false - login, true - reg
    bool emailChange = true, loginChange = true,
         passChange = true, newChatCreate = true, // false - chatting, true - creating new chat
         invNewUserMode = true,
         loginedUser = false; // вошел ли юзер в аккаунт
    bool autoLog = false;
    QString loginAuto, passAuto;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readData();
    void writeData(int stat);

private slots:
    void on_changeModeButton_clicked();
    void on_SignButton_clicked();
    void on_ChangePassBtn_clicked();
    void on_ChangeEmailBtn_clicked();
    void on_changeLoginBtn_clicked();
    void on_checkBox_2_stateChanged(int arg1);
    void on_logoutBtn_clicked();
    void on_listWidget_itemSelectionChanged();
    void changeChatMode();
    void on_pushButton_clicked();
    void on_CreateNewChat_clicked();
    void on_InviteUserBtn_clicked();
    void on_leaveChatBtn_clicked();
    void changeInvUserMode();
    void on_InvUserBtn_clicked();
    void on_ChatLine_returnPressed();
    void changeAccountStatus(bool newStatus);
    void on_tabWidget_currentChanged(int index);

private:
    QString homeDir;
    QMap<QString, chat> chats;
    QMap<QString, invite> invites;
    QString currentChat;
    void changeMode();
    void changePassMode();
    void changeEmailMode();
    void changeLoginMode();
    void createNewChat();
    void setLoginTabEnable(bool setTo);

    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
