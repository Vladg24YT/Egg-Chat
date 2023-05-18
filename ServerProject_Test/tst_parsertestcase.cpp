#include <QtTest>
#include "../ServerProject/DBWorker.h"

// add necessary includes here

class ParserTestCase : public QObject
{
    Q_OBJECT

public:
    ParserTestCase();
    ~ParserTestCase();

private slots:
    void test_case1();

};

ParserTestCase::ParserTestCase()
{
    DBWorker::getInstance()->createDB();
}

ParserTestCase::~ParserTestCase()
{
    DBWorker::getInstance()->close();
}

void ParserTestCase::test_case1()
{
    //QVERIFY(true == DBWorker::getInstance()->searchUser("старый дед"));
   QVERIFY2(true == DBWorker::getInstance()->searchUser("старый дед"), "ERROR!");
    //QCOMPARE(true, DBWorker::getInstance()->searchUser("старый дед1"));
}

QTEST_APPLESS_MAIN(ParserTestCase)

#include "tst_parsertestcase.moc"
