#include<iostream>

using namespace std;

void error_msg(initializer_list<string> il){
    for (auto iter = il.begin(); iter != il.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    for (auto &i : il) {
        int a=0;
        int &c=a;
        c=3;
        std::cout << i << std::endl;
    }

}

int main(void)
{
    initializer_list<string> ls;
    error_msg({"wwwwww","bbbbbbbbbbb"});
    return 0;
}
