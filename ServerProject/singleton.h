#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton;

class SingletonDestroyer{
private:
    static Singleton * p_instance;
public:
    ~SingletonDestroyer();
    void init(Singleton*);
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
    static Singleton* getInstance();
};



#endif // SINGLETON_H
