#ifndef INVITE_H
#define INVITE_H

#include <QString>

/*!
 * \brief The invite class
 * Класс приглашения (одного)
 */
class invite
{
private:
    QString chatName;
    QString chatID;
    QString inviterName;
    QString ID;
public:
    /*!
     * \brief invite
     * Конструктор по умолчанию
     */
    invite();
    /*!
     * \brief invite
     * Конструктор с параметрами
     * <br> Все параметры - QString
     * \param invID
     * ID приглашения
     * \param chat
     * Название чата, в который приглашают
     * \param chat_id
     * ID чата, в который приглашают
     * \param inviter
     * Имя приглашающего
     */
    invite(QString invID, QString chat, QString chat_id, QString inviter);
    /*!
     * \brief getID
     * Возвращает ID приглашения
     * \return [QString] inviteID - ID приглашения
     */
    QString getID();
    /*!
     * \brief toString
     * Возвращает строку с информацией о приглашении
     * <br> для отображения пользователю
     * \return [QString] str - строка для пользователя
     */
    QString toString();
    /*!
     * \brief answer
     * Возвращает строку/команду для ответа на приглашение
     * \param [bool]answer
     *  True - принять приглашение
     *  <br> False - отклонить приглашение
     * \return [QString] - команда для ответа на приглашение
     */
    QString answer(bool answer); // true - accept, false - decline
};

#endif // INVITE_H
