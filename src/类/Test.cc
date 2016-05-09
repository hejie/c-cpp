#include<iostream>
#include "Screen.h"


int main(void)
{

    Screen myScreen(2,3,'x');
    myScreen.move(1,0).set('#').display(std::cout);

    std::cout<<"\n";
    myScreen.display(std::cout);

    
    std::cout<<"\n";

    Screen s;
    return 0;
}
