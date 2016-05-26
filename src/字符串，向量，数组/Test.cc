#include<iostream>
#include <string>
#include <cstring>

int main(void)
{
    std::cout << 10u << std::endl;
    std::string  a("ccc\0c");
    const char *s=a.c_str();
    std::cout << u'c' << std::endl;
    std::cout << a[0] << std::endl;
    std::cout << s << std::endl;
    const  std::string str=s;
    std::cout << str << std::endl;
    std::cout << std::strlen(s)<< std::endl;
    return 0;
}
