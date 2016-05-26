#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Employee{

    private :
        static int sn;
    public :
        Employee(void){
            mysn=sn++;
            std::cout << "默认构造" << std::endl;
        }
        Employee(const string &s){
            name=s;
            mysn=sn++;
            std::cout << mysn << std::endl;
        }

        Employee(const Employee &e){
            name=e.name;
            mysn=sn++;
        }
        Employee& operator=(const Employee &e){
            name=e.name;
            std::cout << (*this).mysn<<" -------- "<<e.mysn<< std::endl;
            return *this;
        }

    private :
        int mysn;
        string name;

    public :
        int getMysn(){
            static Employee i;//调用默认构造函数
            return mysn;
        }

        string getName(){
            return name;
        }

};

void f(Employee &e){
    std::cout << e.getName()<<" "<<e.getMysn() << std::endl;
}

int Employee::sn=1;

int main(void)
{

    //Employee e[10];
    //static Employee e;

    Employee a("hejie"),b("wwwwww");
    a=b;
    Employee c=b;
    f(a),f(b),f(c);
    return 0;
}
