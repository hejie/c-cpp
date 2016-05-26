#include <iostream> 
#include <iterator> 
#include <numeric>
#include <vector> 
#include <algorithm> 

using namespace std;

int main(void)
{
    //std::istream_iterator<int> in(cin),eof;
    //std::cout << std::accumulate(in,eof,0) << std::endl;

    vector<int> v{1,2,3,4,5,6,7};
    std::ostream_iterator<int> out(cout," ");
    for(auto i:v){
      *out++ =i;
    }

    vector<int> v1{1,2,3};
    //std::remove_copy_if(v.begin(),v.end(),std::back_inserter(v1),[](int i){return i&1;});
    //std::replace_copy(v.begin(),v.end(),std::back_inserte
    std::replace_copy_if(v.begin(),v.end(),std::back_inserter(v1),[](int i){return i&1;},8);
    for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
        std::cout << *iter << std::endl;
    } 
    return 0;
}
