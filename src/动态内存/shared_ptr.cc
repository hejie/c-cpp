#include <iostream>
#include <memory>
#include <list>
#include <string>

using namespace std;

void process(shared_ptr<int> ptr){
    std::cout << *ptr << std::endl;
}
int main(void)
{
    std::shared_ptr<string> p1=make_shared<string>("hi");

    shared_ptr<std::list<int>> p2;
    if(!p1->empty()){
        *p1="hi hello";
        std::cout << *p1 << std::endl;
    }


    //int i=1,*pki=&i;
    //shared_ptr<int> sp(pki);//默认shared_ptr 必须指向动态分配的内存对象,必须用直接初始化形式


    shared_ptr<int> pt(new int());
    process(pt);
    std::cout << *pt << std::endl;
/*    auto p=new int();*/
    //auto sp1=make_shared<int>();
    //process(sp1);
    //process(shared_ptr<int>(p)); //必须显示转换


    auto pki=pt.get(); 
    {
       shared_ptr<int>(pki); 
    }
    int foo=*pki;

    return 0;
}
