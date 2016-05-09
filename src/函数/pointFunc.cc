#include<iostream>

#include<vector>

int func1(double =1,int=2){
    return 10;
}

int func1(int ,double=2){
    return 0;
}

using u=int (int,int);

u func2,func3;

std::vector<decltype(func2) *> v;

int main(void)
{

    std::cout << func1() << std::endl;

    std::vector<int> v;
    std::cout << func2(10,20) << std::endl;

    return 0;

}


