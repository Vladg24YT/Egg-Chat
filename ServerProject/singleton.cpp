#include "singleton.h"

SingletonDestroyer::~SingletonDestroyer(){
    delete p_instance;
}
void SingletonDestroyer::init(Singleton * p){
    p_instance = p;
}

Singleton* Singleton::getInstance(){
    if (!p_instance){
        p_instance = new Singleton();
        destroyer.init(p_instance);
    }
    return p_instance;
}

Singleton* Singleton::p_instance;
SingletonDestroyer Singleton::destroyer;
Singleton* SingletonDestroyer::p_instance;
