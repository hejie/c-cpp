#include<iostream>
#include <vector>
#include <list>
#include<cstddef>

int main(void)
{
    int ia[]={0,1,1,2,3,5,8,13,21,55,89,100};

    auto begin=std::begin(ia);
    auto end=std::end(ia);
    ptrdiff_t size=end-begin;

    //两种方式初始化
    std::vector<int> v(ia,ia+size);
    std::list<int> l(ia,ia+size);

    v.assign(ia,ia+size);
    l.assign(ia,ia+size);


    /*   while(begin!=end)*/
    //{
    //v.push_back(*begin);
    //l.push_back(*begin);
    //++begin;
    //}

    for (auto iter = v.begin(); iter != v.end();) {
        if(*iter&1){
            iter++;
        }else {
            iter=v.erase(iter);
        };
    }
 
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        std::cout <<*iter<<" ";
    }

    std::cout << '\n' << std::endl;

    for (auto iter = l.begin(); iter != l.end();) {
        if(*iter&1){
            iter=l.erase(iter);
        }else {
            iter++;
        };
    }
    for (auto iter = l.begin(); iter != l.end(); ++iter) {
        std::cout << *iter<<" " ;
    }



    return 0;
}
