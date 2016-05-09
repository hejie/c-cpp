#include<iostream>

void swapPointer1(int *p,int *q){

    int *temp=p;
    p=q;
    q=temp;

    *p=5;
    std::cout << &p<<"======"<<&q<< std::endl;

}

void swapPointer2(int *p,int *q) {

    int temp=*p;
    *p=*q;
    *q=temp;
}


void swapPointer3(int &a,int &b){

    int temp=a;
    a=b;
    b=temp;

}

void swapPointer4(int *&a,int *&b) {

    int temp =*a;
    int *temp2=a;
    std::cout <<temp<<" 等价于 "<< *temp2 << std::endl;
    *a=*b;
    *b=temp;
}
int main(void)
{
    int a=2,b=3;
    swapPointer2(&a,&b);
    std::cout << a<<" "<<b << std::endl;


    a=2,b=3;
    swapPointer3(a,b);
    std::cout << a<<" "<<b << std::endl;


    a=2,b=3;
    int *c=&a,*d=&b;
    swapPointer4(c,d);
    std::cout << a<<" "<<b << std::endl;
    std::cout << *c<<" "<<*d << std::endl;
    return 0;
}
