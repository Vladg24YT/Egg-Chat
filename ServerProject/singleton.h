#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton;
/// <summary>
/// Класс синглтон дестроера
/// </summary>
class SingletonDestroyer{
private:
    static Singleton * p_instance;
public:
    ~SingletonDestroyer();
    void init(Singleton*);
};
/// <summary>
/// Класс синглтона
/// </summary>
class Singleton{
    /// <summary>
    /// Предоставление доступа классу SingletonDestroyer
    /// </summary>
    friend class SingletonDestroyer;
private:
    static Singleton * p_instance;
    static SingletonDestroyer destroyer;
protected:
    /// <summary>
    /// Конструктор класса Singleton.
    /// </summary>
    Singleton(){}
    /// <summary>
    /// Блокировка конструктора копирования.
    /// </summary>
    /// <param name=""></param>
    Singleton(const Singleton&) = delete;
    /// <summary>
    /// Блокировка оператора равно (=).
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    Singleton& operator = (Singleton&) = delete;
public:
    /// <summary>
    /// Метод получения экземпляра данного класса.
    /// </summary>
    /// <returns>Экземпляра данного класса</returns>
    static Singleton* getInstance();
};



#endif // SINGLETON_H
