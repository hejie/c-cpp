#include<iostream>
#include "Screen.h"


int main(void)
{

    Screen myScreen(2,3,'x');
    myScreen.move(1,0).set('#').display(std::cout);

    std::cout<<"\n";
    myScreen.display(std::cout);

    Screen ecn=myScreen;

    std::cout<<"\n";

    std::cout << "-----------------" << std::endl;
    //vector<string> str(10);

    vector<Screen> s(10);


    for (auto i :myScreen.screens) {
        std::cout << i.get() << std::endl;
    }
    return 0;
}
