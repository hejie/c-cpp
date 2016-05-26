#include <iostream>

using namespace std;
class CExample
{
    private:
        int a;

    public:
        //构造函数
        CExample(int b)
        {
            a = b;
            cout<<"creat: "<<a<<endl;
        }

        //拷贝构造
        CExample(const CExample& C)
        {
            a = C.a;
            cout<<"copy"<<endl;
        }

        //析构函数
        ~CExample()
        {
            cout<< "delete: "<<a<<endl;
        }

        void Show ()
        {
            cout<<a<<endl;
        }
};

//全局函数，传入的是对象
void g_Fun(CExample C)
{
    cout<<"test"<<endl;
}   //全局函数
CExample g_Fun()
{
    CExample temp(0);
    return temp;
}

int main()
{
    //CExample test(1);
    ////传入对象
    //g_Fun(test);

    g_Fun();

    return 0;
}
