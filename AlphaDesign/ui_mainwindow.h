/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *AuthTab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *ConStatLabel;
    QLabel *Login;
    QLineEdit *LoginLine;
    QLabel *Email;
    QLineEdit *EmailLine;
    QLabel *Pass;
    QLineEdit *PassLine;
    QLabel *Pass_2;
    QLineEdit *PassLine_2;
    QPushButton *SignButton;
    QPushButton *changeModeButton;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *ChatsTab;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *NewChatSp1;
    QLabel *InvUserLabel;
    QLineEdit *InvUserIDLine;
    QPushButton *InvUserBtn;
    QHBoxLayout *horizontalLayout;
    QLabel *CurrentChatName;
    QPushButton *InviteUserBtn;
    QPushButton *leaveChatBtn;
    QTextBrowser *ChatBrowser;
    QLabel *NewChatLabel;
    QFrame *NewChatHLine;
    QLabel *NewChatNameLabel;
    QLineEdit *NewChatNameLine;
    QLabel *NewChatDescLabel;
    QTextEdit *NewChatDesc;
    QPushButton *CreateNewChat;
    QLineEdit *ChatLine;
    QSpacerItem *NewChatSp2;
    QFrame *line_2;
    QWidget *AccountTab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *AcountNameLabel;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *AccountLoginLabel;
    QLineEdit *NewLogin;
    QPushButton *changeLoginBtn;
    QLabel *label_4;
    QLabel *AccountEmalLabel;
    QLineEdit *NewEmailLine;
    QPushButton *ChangeEmailBtn;
    QLabel *OldPassLabel;
    QLineEdit *oldPassLine;
    QLabel *NewPassLabel;
    QLineEdit *NewPassLine;
    QLabel *NewPassLabel2;
    QLineEdit *NewPassLine_2;
    QPushButton *ChangePassBtn;
    QPushButton *logoutBtn;
    QSpacerItem *verticalSpacer_4;
    QWidget *NotificationTab;
    QVBoxLayout *verticalLayout_6;
    QListWidget *NotifList;
    QPushButton *InviteAccept;
    QPushButton *InviteDecline;
    QWidget *SettingsTab;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *label;
    QFrame *line;
    QCheckBox *checkBox_2;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 753);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(44, 44, 44, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(66, 66, 66, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(55, 55, 55, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(22, 22, 22, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(29, 29, 29, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(71, 71, 71, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        QBrush brush9(QColor(255, 255, 255, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        QBrush brush10(QColor(240, 240, 240, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        QBrush brush11(QColor(227, 227, 227, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        QBrush brush12(QColor(160, 160, 160, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        QBrush brush13(QColor(105, 105, 105, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush13);
        QBrush brush14(QColor(245, 245, 245, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        QBrush brush15(QColor(0, 0, 0, 128));
        brush15.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush15);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabPosition(QTabWidget::North);
        AuthTab = new QWidget();
        AuthTab->setObjectName("AuthTab");
        gridLayout_2 = new QGridLayout(AuthTab);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        ConStatLabel = new QLabel(AuthTab);
        ConStatLabel->setObjectName("ConStatLabel");
        QFont font;
        font.setPointSize(11);
        ConStatLabel->setFont(font);
        ConStatLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ConStatLabel);

        Login = new QLabel(AuthTab);
        Login->setObjectName("Login");
        Login->setFont(font);
        Login->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Login);

        LoginLine = new QLineEdit(AuthTab);
        LoginLine->setObjectName("LoginLine");
        LoginLine->setMaximumSize(QSize(200, 16777215));
        LoginLine->setFont(font);
        LoginLine->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LoginLine);

        Email = new QLabel(AuthTab);
        Email->setObjectName("Email");
        Email->setFont(font);
        Email->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Email);

        EmailLine = new QLineEdit(AuthTab);
        EmailLine->setObjectName("EmailLine");
        EmailLine->setMaximumSize(QSize(200, 16777215));
        EmailLine->setFont(font);
        EmailLine->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(EmailLine);

        Pass = new QLabel(AuthTab);
        Pass->setObjectName("Pass");
        Pass->setFont(font);
        Pass->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Pass);

        PassLine = new QLineEdit(AuthTab);
        PassLine->setObjectName("PassLine");
        PassLine->setMaximumSize(QSize(200, 16777215));
        PassLine->setFont(font);
        PassLine->setEchoMode(QLineEdit::Password);
        PassLine->setAlignment(Qt::AlignCenter);
        PassLine->setClearButtonEnabled(false);

        verticalLayout->addWidget(PassLine);

        Pass_2 = new QLabel(AuthTab);
        Pass_2->setObjectName("Pass_2");
        Pass_2->setFont(font);
        Pass_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Pass_2);

        PassLine_2 = new QLineEdit(AuthTab);
        PassLine_2->setObjectName("PassLine_2");
        PassLine_2->setMaximumSize(QSize(200, 16777215));
        PassLine_2->setFont(font);
        PassLine_2->setEchoMode(QLineEdit::Password);
        PassLine_2->setAlignment(Qt::AlignCenter);
        PassLine_2->setClearButtonEnabled(false);

        verticalLayout->addWidget(PassLine_2);

        SignButton = new QPushButton(AuthTab);
        SignButton->setObjectName("SignButton");
        SignButton->setMaximumSize(QSize(200, 16777215));
        SignButton->setFont(font);

        verticalLayout->addWidget(SignButton);

        changeModeButton = new QPushButton(AuthTab);
        changeModeButton->setObjectName("changeModeButton");
        changeModeButton->setMaximumSize(QSize(200, 16777215));
        changeModeButton->setFont(font);

        verticalLayout->addWidget(changeModeButton);

        checkBox = new QCheckBox(AuthTab);
        checkBox->setObjectName("checkBox");
        checkBox->setFont(font);
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(AuthTab, QString());
        ChatsTab = new QWidget();
        ChatsTab->setObjectName("ChatsTab");
        formLayout = new QFormLayout(ChatsTab);
        formLayout->setObjectName("formLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        listWidget = new QListWidget(ChatsTab);
        listWidget->setObjectName("listWidget");
        QPalette palette1;
        QBrush brush16(QColor(67, 67, 67, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush16);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush17(QColor(0, 120, 215, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush17);
        listWidget->setPalette(palette1);
        listWidget->setFont(font);

        verticalLayout_4->addWidget(listWidget);

        pushButton = new QPushButton(ChatsTab);
        pushButton->setObjectName("pushButton");
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        pushButton->setFont(font1);

        verticalLayout_4->addWidget(pushButton);


        formLayout->setLayout(1, QFormLayout::LabelRole, verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        NewChatSp1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(NewChatSp1);

        InvUserLabel = new QLabel(ChatsTab);
        InvUserLabel->setObjectName("InvUserLabel");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        InvUserLabel->setFont(font2);

        verticalLayout_5->addWidget(InvUserLabel);

        InvUserIDLine = new QLineEdit(ChatsTab);
        InvUserIDLine->setObjectName("InvUserIDLine");
        InvUserIDLine->setFont(font);
        InvUserIDLine->setMaxLength(64);

        verticalLayout_5->addWidget(InvUserIDLine);

        InvUserBtn = new QPushButton(ChatsTab);
        InvUserBtn->setObjectName("InvUserBtn");
        InvUserBtn->setFont(font);

        verticalLayout_5->addWidget(InvUserBtn);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        CurrentChatName = new QLabel(ChatsTab);
        CurrentChatName->setObjectName("CurrentChatName");
        CurrentChatName->setFont(font2);

        horizontalLayout->addWidget(CurrentChatName);

        InviteUserBtn = new QPushButton(ChatsTab);
        InviteUserBtn->setObjectName("InviteUserBtn");
        InviteUserBtn->setMaximumSize(QSize(28, 28));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        InviteUserBtn->setFont(font3);

        horizontalLayout->addWidget(InviteUserBtn);

        leaveChatBtn = new QPushButton(ChatsTab);
        leaveChatBtn->setObjectName("leaveChatBtn");
        leaveChatBtn->setMaximumSize(QSize(28, 28));
        leaveChatBtn->setFont(font3);

        horizontalLayout->addWidget(leaveChatBtn);


        verticalLayout_5->addLayout(horizontalLayout);

        ChatBrowser = new QTextBrowser(ChatsTab);
        ChatBrowser->setObjectName("ChatBrowser");
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ChatBrowser->sizePolicy().hasHeightForWidth());
        ChatBrowser->setSizePolicy(sizePolicy1);
        ChatBrowser->setFont(font);

        verticalLayout_5->addWidget(ChatBrowser);

        NewChatLabel = new QLabel(ChatsTab);
        NewChatLabel->setObjectName("NewChatLabel");
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        NewChatLabel->setFont(font4);
        NewChatLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(NewChatLabel);

        NewChatHLine = new QFrame(ChatsTab);
        NewChatHLine->setObjectName("NewChatHLine");
        NewChatHLine->setFrameShape(QFrame::HLine);
        NewChatHLine->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(NewChatHLine);

        NewChatNameLabel = new QLabel(ChatsTab);
        NewChatNameLabel->setObjectName("NewChatNameLabel");
        NewChatNameLabel->setFont(font2);
        NewChatNameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(NewChatNameLabel);

        NewChatNameLine = new QLineEdit(ChatsTab);
        NewChatNameLine->setObjectName("NewChatNameLine");
        NewChatNameLine->setFont(font1);
        NewChatNameLine->setMaxLength(64);

        verticalLayout_5->addWidget(NewChatNameLine);

        NewChatDescLabel = new QLabel(ChatsTab);
        NewChatDescLabel->setObjectName("NewChatDescLabel");
        NewChatDescLabel->setFont(font2);
        NewChatDescLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(NewChatDescLabel);

        NewChatDesc = new QTextEdit(ChatsTab);
        NewChatDesc->setObjectName("NewChatDesc");
        NewChatDesc->setFont(font1);

        verticalLayout_5->addWidget(NewChatDesc);

        CreateNewChat = new QPushButton(ChatsTab);
        CreateNewChat->setObjectName("CreateNewChat");
        CreateNewChat->setFont(font);

        verticalLayout_5->addWidget(CreateNewChat);

        ChatLine = new QLineEdit(ChatsTab);
        ChatLine->setObjectName("ChatLine");
        ChatLine->setFont(font);
        ChatLine->setMaxLength(255);

        verticalLayout_5->addWidget(ChatLine);

        NewChatSp2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(NewChatSp2);


        formLayout->setLayout(1, QFormLayout::FieldRole, verticalLayout_5);

        line_2 = new QFrame(ChatsTab);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(0, QFormLayout::FieldRole, line_2);

        tabWidget->addTab(ChatsTab, QString());
        AccountTab = new QWidget();
        AccountTab->setObjectName("AccountTab");
        verticalLayout_2 = new QVBoxLayout(AccountTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        AcountNameLabel = new QLabel(AccountTab);
        AcountNameLabel->setObjectName("AcountNameLabel");
        AcountNameLabel->setMinimumSize(QSize(200, 0));
        AcountNameLabel->setMaximumSize(QSize(200, 16777215));
        AcountNameLabel->setFont(font4);
        AcountNameLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(AcountNameLabel, 0, 0, 1, 1);

        label_2 = new QLabel(AccountTab);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(200, 0));
        label_2->setMaximumSize(QSize(200, 16777215));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 0, 1, 1);

        AccountLoginLabel = new QLabel(AccountTab);
        AccountLoginLabel->setObjectName("AccountLoginLabel");
        AccountLoginLabel->setMinimumSize(QSize(200, 0));
        AccountLoginLabel->setMaximumSize(QSize(200, 16777215));
        QFont font5;
        font5.setPointSize(11);
        font5.setItalic(true);
        AccountLoginLabel->setFont(font5);
        AccountLoginLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(AccountLoginLabel, 3, 0, 1, 1);

        NewLogin = new QLineEdit(AccountTab);
        NewLogin->setObjectName("NewLogin");
        NewLogin->setMinimumSize(QSize(200, 0));
        NewLogin->setMaximumSize(QSize(200, 16777215));
        NewLogin->setFont(font);
        NewLogin->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(NewLogin, 4, 0, 1, 1);

        changeLoginBtn = new QPushButton(AccountTab);
        changeLoginBtn->setObjectName("changeLoginBtn");
        changeLoginBtn->setMinimumSize(QSize(200, 0));
        changeLoginBtn->setMaximumSize(QSize(200, 16777215));
        changeLoginBtn->setFont(font);

        gridLayout_3->addWidget(changeLoginBtn, 5, 0, 1, 1);

        label_4 = new QLabel(AccountTab);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(200, 0));
        label_4->setMaximumSize(QSize(200, 16777215));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_4, 6, 0, 1, 1);

        AccountEmalLabel = new QLabel(AccountTab);
        AccountEmalLabel->setObjectName("AccountEmalLabel");
        AccountEmalLabel->setMinimumSize(QSize(200, 0));
        AccountEmalLabel->setMaximumSize(QSize(200, 16777215));
        AccountEmalLabel->setFont(font5);
        AccountEmalLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(AccountEmalLabel, 7, 0, 1, 1);

        NewEmailLine = new QLineEdit(AccountTab);
        NewEmailLine->setObjectName("NewEmailLine");
        NewEmailLine->setMinimumSize(QSize(200, 0));
        NewEmailLine->setMaximumSize(QSize(200, 16777215));
        NewEmailLine->setFont(font);
        NewEmailLine->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(NewEmailLine, 8, 0, 1, 1);

        ChangeEmailBtn = new QPushButton(AccountTab);
        ChangeEmailBtn->setObjectName("ChangeEmailBtn");
        ChangeEmailBtn->setMinimumSize(QSize(200, 0));
        ChangeEmailBtn->setMaximumSize(QSize(200, 16777215));
        ChangeEmailBtn->setFont(font);

        gridLayout_3->addWidget(ChangeEmailBtn, 9, 0, 1, 1);

        OldPassLabel = new QLabel(AccountTab);
        OldPassLabel->setObjectName("OldPassLabel");
        OldPassLabel->setMinimumSize(QSize(200, 0));
        OldPassLabel->setMaximumSize(QSize(200, 16777215));
        OldPassLabel->setFont(font);
        OldPassLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(OldPassLabel, 10, 0, 1, 1);

        oldPassLine = new QLineEdit(AccountTab);
        oldPassLine->setObjectName("oldPassLine");
        oldPassLine->setMinimumSize(QSize(200, 0));
        oldPassLine->setMaximumSize(QSize(200, 16777215));
        oldPassLine->setFont(font);
        oldPassLine->setEchoMode(QLineEdit::Password);
        oldPassLine->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(oldPassLine, 11, 0, 1, 1);

        NewPassLabel = new QLabel(AccountTab);
        NewPassLabel->setObjectName("NewPassLabel");
        NewPassLabel->setMinimumSize(QSize(200, 0));
        NewPassLabel->setMaximumSize(QSize(200, 16777215));
        NewPassLabel->setFont(font);
        NewPassLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(NewPassLabel, 12, 0, 1, 1);

        NewPassLine = new QLineEdit(AccountTab);
        NewPassLine->setObjectName("NewPassLine");
        NewPassLine->setMinimumSize(QSize(200, 0));
        NewPassLine->setMaximumSize(QSize(200, 16777215));
        NewPassLine->setFont(font);
        NewPassLine->setEchoMode(QLineEdit::Password);
        NewPassLine->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(NewPassLine, 13, 0, 1, 1);

        NewPassLabel2 = new QLabel(AccountTab);
        NewPassLabel2->setObjectName("NewPassLabel2");
        NewPassLabel2->setMinimumSize(QSize(200, 0));
        NewPassLabel2->setMaximumSize(QSize(200, 16777215));
        NewPassLabel2->setFont(font);
        NewPassLabel2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(NewPassLabel2, 14, 0, 1, 1);

        NewPassLine_2 = new QLineEdit(AccountTab);
        NewPassLine_2->setObjectName("NewPassLine_2");
        NewPassLine_2->setMinimumSize(QSize(200, 0));
        NewPassLine_2->setMaximumSize(QSize(200, 16777215));
        NewPassLine_2->setFont(font);
        NewPassLine_2->setEchoMode(QLineEdit::Password);
        NewPassLine_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(NewPassLine_2, 15, 0, 1, 1);

        ChangePassBtn = new QPushButton(AccountTab);
        ChangePassBtn->setObjectName("ChangePassBtn");
        ChangePassBtn->setMinimumSize(QSize(200, 0));
        ChangePassBtn->setMaximumSize(QSize(200, 16777215));
        ChangePassBtn->setFont(font);

        gridLayout_3->addWidget(ChangePassBtn, 16, 0, 1, 1);

        logoutBtn = new QPushButton(AccountTab);
        logoutBtn->setObjectName("logoutBtn");
        logoutBtn->setMinimumSize(QSize(200, 0));
        logoutBtn->setMaximumSize(QSize(200, 16777215));
        logoutBtn->setFont(font);

        gridLayout_3->addWidget(logoutBtn, 17, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 18, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        tabWidget->addTab(AccountTab, QString());
        NotificationTab = new QWidget();
        NotificationTab->setObjectName("NotificationTab");
        verticalLayout_6 = new QVBoxLayout(NotificationTab);
        verticalLayout_6->setObjectName("verticalLayout_6");
        NotifList = new QListWidget(NotificationTab);
        NotifList->setObjectName("NotifList");
        NotifList->setFont(font);

        verticalLayout_6->addWidget(NotifList);

        InviteAccept = new QPushButton(NotificationTab);
        InviteAccept->setObjectName("InviteAccept");
        InviteAccept->setFont(font);

        verticalLayout_6->addWidget(InviteAccept);

        InviteDecline = new QPushButton(NotificationTab);
        InviteDecline->setObjectName("InviteDecline");
        InviteDecline->setFont(font);

        verticalLayout_6->addWidget(InviteDecline);

        tabWidget->addTab(NotificationTab, QString());
        SettingsTab = new QWidget();
        SettingsTab->setObjectName("SettingsTab");
        horizontalLayout_3 = new QHBoxLayout(SettingsTab);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(311, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_5 = new QSpacerItem(20, 280, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        label = new QLabel(SettingsTab);
        label->setObjectName("label");
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        line = new QFrame(SettingsTab);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        checkBox_2 = new QCheckBox(SettingsTab);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setFont(font);

        verticalLayout_3->addWidget(checkBox_2);

        label_5 = new QLabel(SettingsTab);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        verticalSpacer_6 = new QSpacerItem(20, 279, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(310, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        tabWidget->addTab(SettingsTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ConStatLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272 \321\201\320\265\321\200\320\262\320\265\321\200\321\203...", nullptr));
        Login->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        Email->setText(QCoreApplication::translate("MainWindow", "E-mail:", nullptr));
        Pass->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        Pass_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214:", nullptr));
        SignButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        changeModeButton->setText(QCoreApplication::translate("MainWindow", "\320\243 \320\274\320\265\320\275\321\217 \320\265\321\211\321\221 \320\275\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\274\320\275\320\270\321\202\320\265 \320\274\320\265\320\275\321\217 \320\277\320\266 :3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AuthTab), QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \321\207\320\260\321\202", nullptr));
        InvUserLabel->setText(QCoreApplication::translate("MainWindow", "ID-\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        InvUserIDLine->setText(QString());
        InvUserIDLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        InvUserBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        CurrentChatName->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\207\320\260\321\202\320\260", nullptr));
        InviteUserBtn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        leaveChatBtn->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        NewChatLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\207\320\260\321\202", nullptr));
        NewChatNameLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\207\320\260\321\202\320\260:", nullptr));
        NewChatNameLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\207\320\260\321\202", nullptr));
        NewChatDescLabel->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", nullptr));
        NewChatDesc->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        CreateNewChat->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ChatsTab), QCoreApplication::translate("MainWindow", "\320\247\320\260\321\202\321\213", nullptr));
        AcountNameLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\234\320\257 \320\220\320\232\320\232\320\220\320\243\320\235\320\242\320\220", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210 \320\273\320\276\320\263\320\270\320\275:", nullptr));
        AccountLoginLabel->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        changeLoginBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\273\320\276\320\263\320\270\320\275", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "E-mail", nullptr));
        AccountEmalLabel->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273. \320\277\320\276\321\207\321\202\320\260 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        ChangeEmailBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 E-mail", nullptr));
        OldPassLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\321\202\320\260\321\200\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        NewPassLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214:", nullptr));
        NewPassLabel2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        ChangePassBtn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AccountTab), QCoreApplication::translate("MainWindow", "\320\220\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        InviteAccept->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
        InviteDecline->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\320\276\320\275\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(NotificationTab), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\263\320\273\320\260\321\210\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\220\320\241\320\242\320\240\320\236\320\231\320\232\320\230", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\267\320\276\320\262\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\234\320\261 \320\265\321\211\321\221 \320\272\320\260\320\272\320\270\321\205</p><p align=\"center\"><span style=\" font-weight:700;\">\320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272</span> \320\275\320\260\320\272\320\270\320\275\320\265\320\274</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SettingsTab), QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
