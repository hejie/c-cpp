#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <vector>
using namespace std;


bool compareIsbn(const int a,const int b){

    return a>b;

}
typedef bool (*pf)(const int,const int);

int main(void)
{
    std::multiset<int,pf> bookstore(compareIsbn);

    bookstore.insert(1);
    bookstore.insert(2);
    bookstore.insert(3);

    for (auto i :bookstore) {
        std::cout << i << std::endl;
    }

    std::multiset<string> c;

    std::vector<string> v{"a","b"};

    std::copy(v.begin(),v.end(),std::inserter(c,c.end()));

    //std::copy(v.begin(),v.end(),std::back_inserter(c));//c没有push_back 方法

    for (auto iter = c.begin(); iter != c.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
    return 0;
}
