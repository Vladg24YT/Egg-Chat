#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QDebug>

class Singleton;
class SingletonDestroyer
{
private:
    static Singleton * p_instance;
public:
    ~SingletonDestroyer() { delete p_instance;}
    void initialize(Singleton * p){p_instance = p;}
};

class Singleton : public QObject
{
    Q_OBJECT
private:
    static Singleton * p_instance;
    static SingletonDestroyer destroyer;
protected:
    explicit Singleton(QObject *parent = nullptr);
    Singleton(Singleton&);
    Singleton operator=(Singleton&);
    ~Singleton(){ destroyer.~SingletonDestroyer(); }
    friend class SingletonDestroyer;

public:

    static Singleton* getInstance(){
        if (!p_instance)
        {
            p_instance = new Singleton();
            destroyer.initialize(p_instance);
        }
        return p_instance;
    }
};
#endif // SINGLETON_H
