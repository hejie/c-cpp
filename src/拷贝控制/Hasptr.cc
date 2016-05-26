#include <iostream>
#include <string>
using namespace std;

class A{
    public :
        A()=default;
        A(const A &){
            std::cout << "A" << std::endl;
        }
        ~A(){}

};
class HasPtr{

    public :
    friend void swap(HasPtr &lhs,HasPtr &rhs);

    HasPtr(const string &s=string()): ps(new string(s)),i(0){
        std::cout <<"普通构造函数"<< std::endl;
    }

    HasPtr(const HasPtr &hp): ps(new string(*hp.ps)),i(hp.i){
        std::cout << "拷贝初始化" << std::endl;
    }

    ~HasPtr(){
        std::cout << "析构函数" << std::endl;
        delete ps;
        ps=nullptr;
    }

    HasPtr& operator=(const HasPtr &hp){
        if(this==&hp){
            return *this;
        }
        std::cout << "拷贝赋值"<< std::endl;

        //auto temp=new string(*hp.ps);
        //delete ps;
        //ps=temp;

        HasPtr temp(hp);
        auto pTemp=temp.ps;
        temp.ps=ps;
        ps=pTemp;

        i=hp.i;
        a=hp.a;
        return *this;

    }

    int getI(){return i;}
    string getPs(){return *ps;}

    private :
    string *ps;
    int i;
    A a;

};

inline void swap(HasPtr &lhs,HasPtr &rhs){

    std::cout << "交换 "<<*lhs.ps<<" 和 "<<*rhs.ps<< std::endl;
    swap(lhs.i,rhs.i);
    swap(lhs.ps,rhs.ps);
}

HasPtr set(HasPtr p){
    cout<<"in set"<<endl;
    HasPtr ret(p);
    cout<<"run set"<<endl;
    return ret;
}
int main(void)
{
    /* cout<<"in main1"<<endl;*/
    //HasPtr hp;
    //cout<<"in main2"<<endl;
    //HasPtr temp=set(hp);
    //cout<<"in main3"<<endl;
    /*hp=temp;*/


    HasPtr h("hi,mom!");
    HasPtr h2(h);
    HasPtr h3=h;
    std::cout << "h: "<<h.getI()<<" "<<h.getPs() << std::endl;



    return 0;
}
