#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(void)
{
    /* string *const p=new string[10];*/
    //string s;
    //string *q=p;

    //while(cin>>s&&q!=p+10){
    //*q++=s;
    //}
    //const size_t size=q-p;
    //std::cout << size << std::endl;
    //delete[] p;



    std::allocator<string> alloc;
    auto p=alloc.allocate(10);
    auto q=p;
    string s;
    while(cin>>s&&q!=p+10){
        alloc.construct(q++,s);
    }

    const size_t size=q-p;
    std::cout << size << std::endl;
    while(q!=p){
        alloc.destroy(--q);
        std::cout << *q << std::endl;//q是指向最后构造的元素之后的位置
    }
    alloc.deallocate(p,10);



    return 0;
}
