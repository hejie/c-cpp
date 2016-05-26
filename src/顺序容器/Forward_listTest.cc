#include<iostream>
#include <forward_list> 

int main(void)
{
    std::forward_list<int> v{1,2,3,4,5};

    std::forward_list<int>::iterator iter=v.before_begin(); 

    v.erase_after(iter);
    

    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        std::cout << *iter << " ";
    } 

    v.resize(6,7);
    std::cout<<'\n';

    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        std::cout << *iter << " ";
    } 
    return 0;
}
