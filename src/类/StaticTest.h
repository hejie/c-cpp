#include<iostream>
#include<string>

using std::string;

#ifndef STATIC_H
#define  STATIC_H

class Data{
 
    constexpr int func(){
      return 0;
    }

    constexpr int a=func();
};

class Execple{

    public :
        Data d;
        static  Execple e;
        static int p;
        static  constexpr int b=0;

        static void func();

        constexpr Execple(Data d);

    private :

        int c;
};

int Execple::p=10;

#endif
