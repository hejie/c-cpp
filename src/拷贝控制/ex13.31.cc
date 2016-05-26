#ifndef EX13_31_H
#define EX13_31_H value

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
class HasPtr
{
    public:
        friend void swap(HasPtr&, HasPtr&);
        friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

        HasPtr(const std::string &s = std::string())
            : ps(new std::string(s)), i(0)
        { }

        HasPtr(const HasPtr &hp)
            : ps(new std::string(*hp.ps)), i(hp.i)
        { }

        HasPtr& operator=(HasPtr tmp)
        {
            this->swap(tmp);
            return *this;
        }

        ~HasPtr()
        {
            delete ps;
        }

        void swap(HasPtr &rhs)
        {
            using std::swap;
            swap(ps, rhs.ps);
            swap(i, rhs.i);
            std::cout << "call swap(HasPtr &rhs)" << std::endl;
        }

        void show() const
        {
            std::cout << *ps << std::endl;
        }
    private:
        std::string *ps;
        int i;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    std::cout << "wwwwwwwwwww" << std::endl;
    return *lhs.ps < *rhs.ps;
}

#endif
int main(void)
{

    std::vector<HasPtr> v{{"1"},{"2"},{"3"},{"4"}};
    //for (int i = 0; i < 5; ++i) {
    //v.push_back(to_string(5-i));
    //}


    sort(v.begin(),v.end());

    for (auto i : v) {
        i.show();
    }

    return 0;
}
