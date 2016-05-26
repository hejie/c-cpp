#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>

int main(void)
{
    std::vector<int> v{1,2,3,4};
    std::sort(v.rbegin(),v.rend());
    for (auto iter = v.rbegin(); iter != v.rend(); ++iter) {
        std::cout << *iter << std::endl;
    }


    std::string line="my,name,is,hejie";
    auto comma=std::find(line.crbegin(),line.crend(),',');
    std::cout << std::string(comma.base(),line.cend()) << std::endl;

    return 0;
}
