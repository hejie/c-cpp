#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    std::vector<int> vi{1,1,2,3,4};
    int val=1;
    int size=vi.size(),new_ele=0;

    std::vector<int>::iterator iter=vi.begin();
    while (iter!=vi.begin()+size/2+new_ele) {
        std::cout <<*iter<<"------"<<*(vi.begin())<<"---------"<<* (vi.begin()+size/2+new_ele) << std::endl;
        if (*iter==val) {

            std::cout << "--1---"<<*iter << std::endl;

            iter=vi.insert(iter,2*val);

            std::cout << "--2---"<<*iter << std::endl;

            new_ele++;
            iter++;iter++;

            std::cout << "--3---"<<*iter<<" " <<new_ele << std::endl;
        }else
        {
            iter++;
            
            std::cout << "--3---"<<*iter<<" " <<new_ele << std::endl;
        }
    }
    for (auto iter = vi.begin(); iter != vi.end(); ++iter) {
        std::cout << *iter <<"-----"<<*(vi.begin())<< std::endl;
    }

    return 0;
}
