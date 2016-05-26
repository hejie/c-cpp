#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
#include <list>
#include <string> 
int main(void)
{
    std::vector<std::string> v_str3{"cccc"},v_str4{"cccc\0"};
    bool result1=std::equal(v_str3.begin(),v_str3.end(),v_str4.begin());
    std::cout << result1 << std::endl;

    std::vector<const char *> v_str1(2,"a"),v_str2{"a","a","b"};
    bool result=std::equal(v_str1.begin(),v_str1.end(),v_str2.begin());
    std::cout << result << std::endl;

    std::vector<int> vec;
    std::fill_n(vec.begin(),vec.size(),0);

    //插入迭代器
    std::vector<int> v;
    auto it=std::back_inserter(v);
    *it=42;
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        std::cout << *iter << std::endl;
    }


    //拷贝算法
    std::list<int> lst{1,2,3,4};
    std::vector<double> v1;
    std::copy(lst.begin(),lst.end(),std::back_inserter(v1));
    //v1.assign(lst.begin(),lst.end());
    for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    /*const char cal[] ="A";*/
    //const char cal2[]="wwwwwwwwA";
    //if(cal<cal2){
    //std::cout << "dddd" << std::endl;
    /* }*/
    return 0;
}
