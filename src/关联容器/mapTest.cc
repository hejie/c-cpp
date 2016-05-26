#include <iostream>
#include <typeinfo>
#include <map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <initializer_list>

using namespace std;


int main(void)
{

    map<std::vector<int>::iterator,int>   m;
    vector<int> vec{1,2};
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        m[iter]=*iter;
    }
    for (const auto &i :m) {
        vector<int>::iterator v=i.first;
        std::cout << *v << std::endl;
        std::cout << i.second<< std::endl;
    }

    map<std::list<int>::iterator,int>   m1;

    list<int> lst{1,2};

    for (auto iter = m1.begin(); iter != m1.end(); ++iter) {
        //m1[iter]=*iter;//有序容器要求关键字必须支持比较操作< ,list不是连续存储，迭代器不支持比较操作
    }

    map<string,size_t> words_count{{"a",1},{"b",2}};
    auto map_it=words_count.begin();
    std::cout << map_it->first << std::endl;
    //std::cout << (*map_it).first << std::endl;

    pair<map<string,size_t>::iterator,bool> pair= words_count.insert({"c",3});
    map<string,size_t>::iterator iter=pair.first;
    std::cout <<iter->second << std::endl;
    initializer_list<map<string,size_t>::value_type> il ={{"e",4},{"d",5}};
    words_count.insert(il);
    std::cout << "initializer_list " <<words_count.find("d")->second<< std::endl;

    ++words_count.insert({"d",3}).first->second;

    const map<string,size_t> map2={{"A",0},{"a",1},{"b",2}};

    //std::cout << map2["a"] << std::endl;
    //std::cout << map2.at("a") << std::endl;

    std::cout <<map2.upper_bound("e")->second << std::endl;
    std::cout << map2.lower_bound("e")->second << std::endl;

    //std::cout << words_count.count("e") << std::endl;//统计返回个数
    //std::cout << words_count.find("d")->second << std::endl;

    for (auto iter = words_count.begin(); iter != words_count.end(); ++iter) {
        std::cout <<iter->second << std::endl;
    }

    using KeyType = std::map<int, std::string>::key_type;

    std::cout << "type to subscript: " << typeid(KeyType).name() << std::endl;
    std::cout << "returned from the subscript operator: " << typeid(words_count["d"]).name() << std::endl;
    std::map<string, string> trans_map;
    string value{" abcde"};
    trans_map["e"] = value.substr(1).substr(0, value.find_last_not_of("ce"));
    for (auto iter = trans_map.begin(); iter != trans_map.end(); ++iter) {
        std::cout << iter->second<< std::endl;
    }
    return 0;
}
