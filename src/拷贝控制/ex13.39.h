#ifndef EX13_19_H
#define EX13_19_H value

#include <iostream>
#include <string>
#include <utility>
#include <memory>
using namespace std;

class StrVec{

    public :
        StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
        StrVec(const StrVec&);
        StrVec &operator=(const StrVec&);
        ~StrVec();
        void push_back(const string&);
        size_t size() const { return first_free-elements;}
        size_t capacity() const {return cap-elements;}
        string *begin() const { return elements;}
        string *end() const {return first_free;}
    private :
        static std::allocator<string> alloc;

        void chk_n_alloc()
        {
            if(size()==capacity()){
                reallocate();
            }
        }

        pair<string*,string*> alloc_n_copy(const string*,const string*);
        void free();
        void  reallocate();
        string *elements;
        string *first_free;
        string *cap;

};
std::allocator<string> StrVec::alloc;

void StrVec::push_back(const string &s){
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

pair<string*,string*> StrVec::alloc_n_copy(const string *b,const string *e){
    auto data=alloc.allocate(e-b);
    return {data,std::uninitialized_copy(b,e,data)};
}

void StrVec::free(){
    if(elements){
        for (auto iter = first_free; iter != elements;) {
            alloc.destroy(--iter);
        }
    }
    alloc.deallocate(elements,cap-elements);
}

StrVec::~StrVec(){
    free();
}

StrVec::StrVec(const StrVec &s){
    auto newdata=alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}

StrVec &StrVec::operator=(const StrVec &s){
    auto newdata=alloc_n_copy(s.begin(),s.end());
    free();
    elements=newdata.first;
    first_free=cap=newdata.second;
    return *this;
}
void StrVec::reallocate(){
    auto new_capacity=size()?size()<<2:1;
    auto new_data=alloc.allocate(new_capacity);

    auto dest=new_data;

    auto elem=elements;

    for (size_t i = 0; i != size(); i++) {
        alloc.construct(dest++,std::move(*elem++));
    }

    free();
    elements=new_data;
    first_free=dest;
    cap=elements+new_capacity;

}



#endif /* ifndef EX13_19_H */
