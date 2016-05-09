#include<iostream>
#include<string>

using std::string;

int main(int argc, char *argv[])
{
    string str;

    std::cout << *argv<<" "<<argv << std::endl;


    for (decltype(argc) i = 0; i!=argc;++i) { 
        str+=argv[i];
    } 
    std::cout << str << std::endl;
    return 0;
}                
