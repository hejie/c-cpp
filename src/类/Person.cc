#include<iostream>

#include<string>

using std::string;

class Person{
    friend std::ostream& print(std::ostream &io,const Person &p);
    friend Person add();
    private :
    string strName;
    string strAddress;

    public :
    Person()= default;
    Person(const string &name,const string &address)
    {
        strName=name;
        strAddress=address;

    }

    Person(std::istream &is)
    {
        is>>strName>>strAddress;
    }

    string getName() const
    {
        return strName;
    }

    private : string getAddress() const
              {
                  return strAddress;
              }
    public :
              void  print() const;

              using pos=std::string::size_type;
              
              Person(pos ht,pos wd,char c): cursor(0),height(ht),width(wd),contents(ht*wd,c){}

    private :
              pos cursor;//如果没有类内初始值，使用前可以在构造的时候进行显示初始化
              pos height=0,width=0;
              std::string contents;
};

Person add()
{
    Person person;
    person.getAddress();
    return person;
}
std::ostream& print(std::ostream &io,const Person &p)
{
    io<<p.getName()<<"  "<<p.getAddress()<< p.getAddress()<<p.cursor;
    return io;
}

void Person::print()const
{
    std::cout << this << std::endl;
}

int main(void)
{

    //构造函数在const对象的构造过程中可以向其写值
    const Person person("bbbbbb","wwww");
    print(std::cout,person) ;

    std::cout  << std::endl;
    //常量对象，以及常量对象的引用或指针都只能调用常量成员函数
    person.print();

    Person person2(10,20,'c');
    print(std::cout,person2);
    return 0;
}
