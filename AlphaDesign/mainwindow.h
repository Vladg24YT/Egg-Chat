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
         passChange = true;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_changeModeButton_clicked();

    void on_SignButton_clicked();

    void on_ChangePassBtn_clicked();

    void on_ChangeEmailBtn_clicked();

    void on_changeLoginBtn_clicked();

private:
    void changeMode();
    void changePassMode();
    void changeEmailMode();
    void changeLoginMode();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
