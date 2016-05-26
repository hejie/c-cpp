#include <memory>
#include <iostream>
#include <vector>

using namespace std;

vector<int>* get(){

    return new (nothrow) vector<int>;
}

void print(vector<int> *vec){
    for (auto iter = vec->begin(); iter != vec->end(); ++iter) {
        std::cout << *iter << std::endl;
    }

}
int main(void)
{
    vector<int> *vec=get();
    int i=0;
    while(cin>>i)
    {
        vec->push_back(i);
    }
    print(vec);
    delete vec;
    vec=nullptr;
    return 0;
}
