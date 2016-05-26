#include <iostream>
#include <string>
using namespace std;

class HasPtr{

    public:
        //HasPtr()=default;

        HasPtr(const string &s=string(),int a=0) : ps(new string(s)),i(a){
            std::cout << "第一个构造" << std::endl;
        }

        HasPtr(const HasPtr &hp):ps(new string(*hp.ps)), i(hp.i){

            std::cout << "拷贝构造函数" << std::endl;
        }
        HasPtr& operator=(const HasPtr &hp);

        void set(HasPtr *hp){
            (*hp).i=10;
        }

        int get(){
            return i;
        }

        ~HasPtr(){
          std::cout << "析构函数" << std::endl;
        }
    private:
        string *ps;
        int &i;

};

HasPtr& HasPtr::operator=(const HasPtr &hp){
    if(this!=&hp){
        auto  temp=new string(*hp.ps);
        std::cout <<"赋值运算符 "<<this<<"  "<< &hp << std::endl;
        delete ps;
        ps=temp;
        i=hp.i;
    }
    return *this;
}

HasPtr global;
HasPtr &func(HasPtr &hp){

    HasPtr local=hp,*head=new HasPtr(global);
    *head=local;
    
    return hp;

}
int main(void)
{
    HasPtr ptr;

   HasPtr hp= func(ptr);
   std::cout << &hp << std::endl;

    //HasPtr ptr2;
    //std::cout <<&ptr<<" " <<&ptr2 << std::endl;
    /*ptr=ptr2;*/

    return 0;
}
