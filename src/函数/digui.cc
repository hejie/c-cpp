#include<iostream>
#include<vector>


using namespace std;

int func(vector<int>::iterator begin,vector<int>::iterator end){

    if(begin==end){
        return 0;

    }
    std::cout << *begin << std::endl;
    return func(++begin,end);
}

int func2(vector<int> v,unsigned int index){

    if(!v.empty()&&v.size()!=index)
    {
        std::cout << v[index] <<" index= "<<index<< std::endl;
        return func2(v,++index);
    }
    return 0;
}

int main(void)
{
    std::vector<int> v{1,2,3,4,5};

    func(v.begin(),v.end());

    func2(v,0);

    return 0;
}
