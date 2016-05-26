#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Folder;

class Message{

    friend class Folder;

    public :
    explicit Message(const string &str=""): contents(str){ }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remvoe(Folder&);

    private :
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();



};

#endif
