#include <map>
#include <iostream>
#include <string>

using namespace std;

namespace ClassFoo{
    void PrintIntDoubleMap(std::map<int,double>& m,string  pre) {
        std::map<int,double>::iterator it;
        std::cout << pre;
        for ( it = m.begin(); it != m.end(); it++ )
            std::cout << "(" << it->first << "," << it->second << ") ";
        std::cout << std::endl;
    }
    void MapExample1() {
        std::map<int,double> foo1;

        // operator[]在主键不存在时，自动创建
        foo1[0] = 32.8;

        // 普通插入
        foo1.insert(std::map<int,double>::value_type(1, 33.2));

        // 带暗示插入，std::pair<int,double>等价于上述的
        // std::map<int,double>::value_type
        foo1.insert(foo1.end(),std::pair<int,double>(2,35.8));

        // 插入一个范围
        std::map<int,double> foo2;
        foo2.insert(std::map<int,double>::value_type(3, 36.4));
        foo2.insert(std::map<int,double>::value_type(4, 37.8));
        foo2.insert(std::map<int,double>::value_type(5, 35.4));
        foo1.insert(foo2.begin(),foo2.end());

        PrintIntDoubleMap(foo1,"插入元素后的foo1：");

        // 查找主键4
        std::map<int,double>::iterator it;
        it = foo1.find(4);
        if( it != foo1.end() )
        {
            std::cout << "foo1.find(4)：";
            std::cout << "(" << it->first << "," << it->second << ")"
                << std::endl;
        }

        // 删除上述找到的元素
        if( it != foo1.end() )
        {
            foo1.erase(it);
        }
        PrintIntDoubleMap(foo1,"删除主键为4的元素后的foo1：");

        // 遍历删除主键为2的元素
        for(it = foo1.begin();it != foo1.end();it++)
        {
            //遍历删除主键等于2
            //注意，删除元素会使迭代范围发生变化
            if(it->first == 2)
            {
                foo1.erase(it);
                break;
            }
        }
        PrintIntDoubleMap(foo1,"删除主键为2的元素后的foo1：");
        foo1.clear();
        PrintIntDoubleMap(foo1,"清空后的foo1：");
    }
}
int main( )
{
    ClassFoo::MapExample1();
    return 0;
}
