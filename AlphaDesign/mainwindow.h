#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool mode = true; // false - login, true - reg
    bool emailChange = true, loginChange = true,
         passChange = true, newChatCreate = true, // false - chatting, true - creating new chat
         invNewUserMode = true;


public:
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

    void changeChatMode();

    void on_pushButton_clicked();

    void on_CreateNewChat_clicked();

    void on_InviteUserBtn_clicked();

    void on_leaveChatBtn_clicked();

    void changeInvUserMode();

    void on_InvUserBtn_clicked();

    void on_ChatLine_returnPressed();

private:
    void changeMode();
    void changePassMode();
    void changeEmailMode();
    void changeLoginMode();
    Ui::MainWindow *ui;
    void createNewChat();
};
#endif // MAINWINDOW_H
