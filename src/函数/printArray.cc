#include<iostream>

using namespace std;

void print1(const int *p){
    std::cout << *p << std::endl;
}

void print2(const int a[], const int *p,const size_t sz){

   const int *size=begin(a);
    while (size!=sz) {
        ++size;
        std::cout <<*p++<< std::endl;
    }

}

int main(void)
{
    int i=0,j[2]={21,2};

    print1(&i);
    print1(j);

    int *size=begin(j)


    return 0;
}
