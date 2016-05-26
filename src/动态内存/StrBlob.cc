#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class StrBlob{
    public :
        typedef std::string::size_type size_type;

        StrBlob();
        explicit StrBlob(std::initializer_list<string> il); //explicit 构造函数只能用于直接初始化，如：a(b),不能a=b; 而直接初始化两者都可以
        StrBlob(StrBlob &sb){
            std::cout << &sb << std::endl;
        }
        StrBlob(string  il);
        size_type size() const { return data->size();}
        bool empty() const { return data->empty(); }
        void push_back(const std::string &s) const {      //const StrBlob *const this
            data->push_back(s);
            //data=make_shared<vector<string>>();//不能改变this的成员
        }
        void push_back(const std::string &s) { data->push_back(s); }
        void pop_back() const;

        std::string& front();
        std::string& back();



    private:
        std::shared_ptr<std::vector<std::string>> data;
        std::shared_ptr<std::vector<std::string>> data2;
        void check(size_type i,const std::string &msg) const;
        shared_ptr<string>  str;
};

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()){
    std::cout << "------------" << std::endl;
}

StrBlob::StrBlob(string il):str(std::make_shared<string>(il)){

    std::cout << "init1" << std::endl;

}


StrBlob::StrBlob(std::initializer_list<string> il): data(std::make_shared<std::vector<string>>(il)){

    std::cout << "init2" << std::endl;

}
                                                               
//直接使用new管理内存,需要手动回收
//StrBlob::StrBlob(std::initializer_list<string> il): data(new vector<string>(il)){

    //std::cout << "init2" << std::endl;

/*}                    */                                                     

void StrBlob::pop_back() const {

    data->pop_back();

}


int main(void)
{

    StrBlob b1;

    {
        const StrBlob b2{"a","an","the"};//直接初始化
        b2.push_back("about");
        b1=b2;
        b2.pop_back();
    }
    std::cout << b1.size() << std::endl;


    return 0;
}
