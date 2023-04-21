#ifndef MODELS_H
#define MODELS_H

#include <QList>
#include <QString>

class Chat
{
public:
    Chat();
    int id;
    int creator_id;
    QString name;
    QString decription;
    QString ToString();
};

class User
{
public:
    User();
    int id;
    int name;
};

#endif // MODELS_H
