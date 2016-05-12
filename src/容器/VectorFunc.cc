#include<iostream>
#include<vector>

void print(std::vector<int>);
int main(void)
{
    std::vector<int> v{1,2,3,4,5};

    auto &front_v=v.front();
    front_v=20;
    std::cout << front_v << std::endl;
    print(v);

    //v.pop_back();
    std::vector<int>::iterator iter=v.begin();
    auto erase= v.erase(iter);//删除后iter失效,
    std::cout << *erase << std::endl;
    print(v);

    auto back=v.back();
    std::cout << back << std::endl;
    print(v);

    auto &at_v=v.at(3);
    at_v=10;
    std::cout << at_v << std::endl;
    print(v);

    auto index=v[3];
    std::cout << index << std::endl;
    print(v);

    std::cout << *iter << std::endl;
    auto end=v.erase(v.end()-2,v.end());
    std::cout << *end << std::endl;
    print(v);
    return 0;
}

void print(std::vector<int> iter){
    std::cout <<'\n';
    for (auto i : iter) {
        std::cout << i<<" ";
    }
    std::cout <<'\n';

}
