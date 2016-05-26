#include <iostream> 
#include <string> 
#include "ex13.39.h" 

using namespace std;

int main(void)
{
    StrVec sv;
    sv.push_back("hello");

    for (auto iter = sv.begin(); iter != sv.end(); ++iter) {
        std::cout << *iter << std::endl;
    } 
    return 0;
}

