#ifndef CHAT_H
#define CHAT_H

#include <QString>
#include <vector>

/*!
 * \brief
 * Структура сообщений для более удобного их хранения
 */
struct message
{
    QString sender; ///< имя отправителя сообщения
    QString text; ///< текст сообщения
    QString time; ///< время отправки сообщения

    /*!
     * \brief message Конструктор сообщения
     * \param [QString]snd имя отправителя
     * \param [QString]txt текст сообщения
     * \param [QString]tm время отправки
     */
    message(QString snd, QString txt, QString tm){
        this->sender = snd;
        this->text = txt;
        this->time = tm;
    }

    /*!
     * \brief show Преобразует сообщение в строку,
     * <br> удобочитаемую человеком
     * \return [QString]
     */
    QString show(){
        return "[" + sender + "] " + text + "\n (" + time + ")";
    }
};

/*!
 * \brief The chat class
 * <br> Класс чата.
 * <br> Хранит сообщения и сведения о чате
 */
class chat
{
private:
    int chat_id;
    int ureadMessages = 0;
public:
    /*!
     * \brief addMessage
     * Добавляет сообщение в вектор сообщений чата
     * \param nm
     * Добавляемое сообщение
     */
    void addMessage(message nm);
    int messagesCount; ///< Счётчик кол-ва сообщений в чате
    std::vector<message> msgs; ///< Вектор, хранящий все сообщения в чате

    /*!
     * \brief chat
     * Конструктор по умолчанию
     */
    chat();
    /*!
     * \brief chat
     * Конструктор, принимает на вход ID чата
     * \param [int]chat_id
     * ID чата
     */
    chat(int chat_id); ///<
    //~chat();
};

#endif // CHAT_H
