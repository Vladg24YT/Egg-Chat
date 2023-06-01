#include <QtTest>
#include "../ServerProject/DBWorker.h"
#include "../AlphaDesign/invite.h"

// add necessary includes here

class ParserTestCase : public QObject
{
    Q_OBJECT

public:
    ParserTestCase();
    ~ParserTestCase();

private slots:
    // для сервера
    void test_case1();
    void test_case2();
    // для клиента
    void test_case3();
    void test_case4();
};

ParserTestCase::ParserTestCase(){
    DBWorker::getInstance()->open();
}

ParserTestCase::~ParserTestCase(){
    DBWorker::getInstance()->close();
}

void ParserTestCase::test_case1(){
   QVERIFY2(true == DBWorker::getInstance()->insertUser("", "12345", "email@email.net"), "Отсутсвует логин!");
}
void ParserTestCase::test_case2(){

   QVERIFY2(true == DBWorker::getInstance()->searchUser("старый дед"), "Пользователь не найден!");
}
void ParserTestCase::test_case3(){
    invite inv = invite("499", "funny chat 23", "75", "user128457");
    QVERIFY2("invite|answer|499|75|1" == inv.answer(true), "Ошибка генерации команды!");
}
void ParserTestCase::test_case4(){

   QVERIFY2("true" == "МЕТОД КЛИЕНТА", "ТЕКСТ ОШИБКИ");
}

QTEST_APPLESS_MAIN(ParserTestCase)

#include "tst_parsertestcase.moc"
