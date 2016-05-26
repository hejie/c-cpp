#ifndef FOLDER_H
#define FOLDER_H 
#include <set>
#include "Message.h"

using namespace std;

class Folder{

    public :
        void addMsg(Message&);
        void remMsg(Message&);
    private :
        set<Message*> messages;

} ;

void Folder::addMsg(Message &msg){
    messages.insert(&msg);
}
void Folder::remMsg(Message &msg){
    messages.erase(&msg);
}


#endif /* ifndef FOLDER_H */
