#include "singleton.h"

Singleton::Singleton(QObject *parent)
    : QObject{parent}
{
    qDebug() << "AAAAAA";
}
Singleton * Singleton::p_instance;
SingletonDestroyer Singleton::destroyer;
Singleton * SingletonDestroyer::p_instance;
