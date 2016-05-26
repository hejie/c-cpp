#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
using namespace std;

//using std::placeholders::_1;
using namespace std::placeholders;

auto f=[](const string &a,const string &b){

    return a.size()<b.size();

};

bool check_size(const string &s,string::size_type sz,string::size_type b){

    return s.size()<sz;
}

bool isShorter(const string &a,const string &b){
    return a.size()<b.size();
}

void print(vector<string>::iterator begin,vector<string>::iterator end){
    for (auto iter = begin; iter != end; ++iter) {
        std::cout << *iter << std::endl;
    }
}


int main(void)
{

    std::vector<string> v{"cab","ac","ab","bac","abc"};

    //std::stable_sort(v.begin(),v.end(),f);
    std::sort(v.begin(),v.end(), bind(isShorter,_1,_2));

    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    unsigned sz=3;
    auto iter=[sz](const string &str){return str.size()>=sz;};
    auto index=   std::find_if(v.begin(),v.end(),iter);

    std::cout << '\n' << std::endl;
    std::for_each(index,v.end(),[](const string &s){
            std::cout << s << std::endl;
            });

    //print(index,v.end());

    //std::cout << '\n' << std::endl;
    //auto check_bind=find_if(v.begin(),v.end(),bind(check_size,_1,2,_2));
    /*print(check_bind,v.end());*/

    /*auto sum=[&sz](int a,int b)->int{*/
    //return a+b+sz;
    /*} ;*/
    //int c=3;
    /*    auto sum=[&](int a,int b)->int{*/
    //return a+b+sz+c;
    //} ;
    /*sz=20;*/

    auto sum=[=](int a,int b) mutable{
        //如果是值类型在内部要改变局部变量值必须加上mutable
        //如果是引用类型则不需要，引用类型是根据所引用的对象是否是const来确定
        return ++sz;
    } ;

    sz=30;

    //std::cout << sum(1,2) << std::endl;


    std::vector<int> v_size{1,2,3,4,5,6,7};
    string check_str="hello";
    auto check=std::bind(check_size,check_str,_1,2);
    auto b1=find_if(v_size.begin(),v_size.end(),check);

    if (b1!=v_size.end()) std::cout << *b1<< std::endl;;


    std::cout << '\n' << std::endl;

    std::list<string> lst;
    auto iter_inserter= std::inserter(lst,lst.begin()) ;
    copy(v.begin(),v.end(),iter_inserter);
    *iter_inserter="wwwwwwwww";
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        std::cout << *iter << std::endl;
    }


    


    return 0;


}
