#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

void output_words(vector<string>::iterator beg,vector<string>::iterator end){

    for (auto iter = beg; iter != end; ++iter) {
        std::cout << *iter << std::endl;
    }
}

bool five_or_more(const string &s){
    return s.size()>=5;
}

int main(int argc, char *argv[])
{
    
    std::cout << argc << std::endl;
    ifstream in(argv[1]);
    if(!in){
      std::cout << "open input file fail" << std::endl;
    }
    
    std::vector<string> words;

    string word;
    while(in>>word){
       words.push_back(word);
    }
    output_words(words.begin(),words.end());
    auto iter=partition(words.begin(),words.end(),five_or_more);
    output_words(words.begin(),iter);
    return 0;
}
