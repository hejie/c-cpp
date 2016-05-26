#include <iostream>
#include <string>
class A
{
    public:
        A(int v) : var(v)
    {
        std::cout << "wwwwww" << std::endl;
    }
        ~A()
        {
            fclose(file);
        }

    private:
        int var;
        FILE *file;
};

int main(void)
{
    auto *pa=new A(10);
    return 0;
}
