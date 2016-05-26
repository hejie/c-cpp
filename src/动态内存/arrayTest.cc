#include <memory>
#include <cstring>
#include <iostream>
#include <new>

using namespace std;

int main(void)
{
    int *arr=new int[2]{1,2};

    string *str =new string[2]{};

    //auto p=new auto();//不能使auto来初始化数组

    //std::cout << *arr << std::endl;


    char *cp=new char[0];
    cp++;
    std::cout << *cp << std::endl;

    int ia[]{1,2,3,4};
    int *p=&ia[2];
    //std::cout << p[1]<<"=="<<*(p+1) << std::endl;


    //unique_ptr<int[]> u;
    unique_ptr<int[]> u(new int[3]{1,2,3});
    //std::cout << u[0]<< std::endl;
    //u.release();


    const char *c1="hello ";
    const char *c2="world";

    char *r =new char[strlen(c1)+strlen(c2)+1];
    strcpy(r,c1);
    strcat(r,c2);
    std::cout << r << std::endl;


    const string s1="hello ";
    const string s2="world";

    strcpy(r,(s1+s2).c_str());
    std::cout << r << std::endl;


    return 0;
}
