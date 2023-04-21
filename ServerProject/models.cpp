#include "models.h"

Chat::Chat()
{

}

QString Chat::ToString(){
    return QString::number(id) + ':' + QString::number(creator_id) + ':' + name + ':' + decription + '\n';
}

User::User()
{

}
