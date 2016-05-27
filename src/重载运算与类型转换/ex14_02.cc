#include "ex14_02.h"

Sales_data::Sales_data(std::istream &is) : Sales_data()
{
    is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    std::cout << "复合赋值运算符" << std::endl;
    return *this;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    std::cout << "加法运算符"<< std::endl;
    return sum;
}
int main(void)
{

    Sales_data data1("n1001",10,2),data2("m1001",10,2);
    //Sales_data data=operator+(data1,data2);
    Sales_data data=data1+data2;
    //data2+=data1;


    //operator>>(std::cin,data1);
    operator<<(std::cout,data);

    return 0;

}
