#include<iostream>
#include "Example.h"

constexpr double  Example::rate;

int main(void)
{
    std::cout << Example::rate << std::endl;
    return 0;
}
