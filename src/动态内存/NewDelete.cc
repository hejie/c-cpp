#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Test{

    public :
        Test()=default;
    private:
        int a;
};

int main(void)
{
    int *a=new int();
    string *str=new string;
    //std::cout << *str << std::endl;
    //std::cout << a << std::endl;

    auto c=new auto(a);
    //auto c=new auto{a};错误
    //std::cout << **c << std::endl;

    int *i=new int(),*pi1=i;
    delete i;
    i=nullptr;
    pi1=nullptr;
    //std::cout << i <<" "<< pi1<< std::endl;
    const int *pki=new const int(1024);
    //std::cout << *pki << std::endl;


    int *q=new int(42),*r=new int(100);

    r=q;
    delete q;

    int t=*q;

    std::cout << t<<" "<<sizeof(r) << std::endl;
    return 0;
}

