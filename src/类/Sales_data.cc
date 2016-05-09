#include<iostream>
#include<string>

using std::string;

using namespace std;
class Sales_data {

    public :
        Sales_data() = default;
        Sales_data(const string &book): bookNo(book){};
        Sales_data(const string &book,const unsigned num,
                const double sellp,const double salep);
        Sales_data(std::istream &is);



    public :
        std::string bookNo;
        unsigned units_sold=0;
        double sellingprice=0.0;
        double saleprice=0.0;
        double discount=0.0;


};

Sales_data::Sales_data(const string &book,const unsigned num,
        const double sellp,const double salep){
    bookNo=book;
    units_sold=num;
    sellingprice=sellp;
    saleprice=salep;
    discount =saleprice / sellingprice;
}

    istream&
read(istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >>item.sellingprice>>item.saleprice;
    return is;
}
    ostream&
print(ostream &os, const Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " "
        << item.sellingprice<< " " << item.saleprice<<" "<<item.discount;
    return os;
}
Sales_data::Sales_data(std::istream &is){
    read(is,*this);

    discount =saleprice / sellingprice;
}


int main(void)
{

    Sales_data data4(cin);

    print(cout,data4);

    return 0;
}
