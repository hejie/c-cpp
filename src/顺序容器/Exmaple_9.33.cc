#include<iostream>
#include <vector>

int main(void)
{
    std::vector<int> v{1,2,3,4,5};
    auto begin=v.begin();
    while(begin!=v.end()){
        ++begin;
        begin=v.insert(begin,8);
        ++begin;
    }
    for (auto i :v) {
        std::cout << i << std::endl;
    }
    return 0;
}

