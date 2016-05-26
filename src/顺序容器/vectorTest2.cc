#include<iostream>
#include <string>
#include <vector>
#include <list>

using std::vector;
using namespace std;

int main(void)
{
    std::list<int> ls={1,2};

    std::list<int> *p=&ls;

    std::vector<double> v(ls.begin(),ls.end());

    for (auto i :v) {
        std::cout << i ;
    }

    std::cout<<'\n';
    std::list<int> ls1={1,2,3};

    ls=ls1;//赋值相关的运算会导致左边的容器内部的迭代器，引用和指针失效
 
    for (auto i :*p) {
        std::cout << i;
    } 
    
    std::cout<<'\n';
    std::vector<double> v3(10,3);
    std::vector<double> *q =&v3;
                      
    for (auto i :*q) {
        std::cout << i;
    }                

    std::cout<<'\n';
    swap(v3,v); //swap运算不会导致左边的容器内部的迭代器，引用和指针失效

    for (auto i :*q) {
        std::cout << i ;
    }

    std::cout<<'\n';
    for (auto i :v3) {
        std::cout << i;
    }


    std::cout<<'\n';

    v.assign(ls.begin(),ls.end());


    for (auto i :v) {
        std::cout << i ;
    }

    std::cout<<'\n';
    vector<int> v1(10,1);
    vector<int> v2(11,2);
    vector<int>::iterator it1 = v1.begin();
    vector<int>::iterator it2 = v2.begin();
    cout<< &v1 << "\t" << &v1[0] << "\t" <<  *it1 << "\t" << *v1.begin() << endl;
    cout<< &v2 << "\t" << &v2[0] << "\t" << *it2 << "\t" << *v2.begin() << endl;
     v1=v2;
    //v1.swap(v2);
       for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
           std::cout << *iter << std::endl;
       } 
   // it1 = v1.begin();
    cout<< &v1 << "\t" << &v1[0] << "\t" <<  *it1 << "\t" << *v1.begin() << endl;
    cout<< &v2 << "\t" << &v2[0] << "\t" << *it2 << "\t" << *v2.begin() << endl;
    return 0;
}
