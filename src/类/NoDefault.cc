#include<iostream>

#include<string>
#include<vector>

using std::string;
using std::vector;

class NoDefault{

    public :
        NoDefault(int i=0){
        }
      
    private:
        int i=0;
        int str;

};

struct A{

    vector<int> vec=vector<int>(10);
    A(int) :d(10)  {
        for(auto i :vec){

            std::cout << i<< std::endl;
        }
    }
    const int d;
    void dd(){

    }
};

int main(void)
{
    A a(0);
    std::vector<NoDefault> v(10,NoDefault(10));

    vector<NoDefault> f(2);//需提供一个默认的构造函数
    vector<NoDefault> n{NoDefault(10)};
    return 0;
}
