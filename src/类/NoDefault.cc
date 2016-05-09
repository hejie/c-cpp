#include<iostream>

#include<string>
#include<vector>

using std::string;
using std::vector;

class NoDefault{

    public :
        NoDefault(int){
        }
        vector<double> v;


        NoDefault(){
            std::cout << "wwwwwwwww" << std::endl;
        }
        void cc(){
            static int c;
        }
    private:
        const int i=0;

};

struct A{

    NoDefault my_mem;
    vector<int> vec=vector<int>(10);
    A(int) :d(0)  {
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
    return 0;
}
