#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton;

class SingletonDestroyer{
private:
    static Singleton * p_instance;
public:
    ~SingletonDestroyer(){ delete p_instance; }
    void init(Singleton * p) { p_instance = p; }
};

class Singleton{
    friend class SingletonDestroyer;
private:
    static Singleton * p_instance;
    static SingletonDestroyer destroyer;
protected:
    Singleton(){}
    Singleton(const Singleton&) = delete;
    Singleton& operator = (Singleton&) = delete;
public:
    static Singleton* getInstance(){
        if (!p_instance){
            p_instance = new Singleton();
            destroyer.init(p_instance);
        }
        return p_instance;
    }
};

Singleton* Singleton::p_instance;
SingletonDestroyer Singleton::destroyer;
Singleton* SingletonDestroyer::p_instance;

#endif // SINGLETON_H
