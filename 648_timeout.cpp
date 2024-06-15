#include<iostream>
#include<vector>
#include <queue>          // std::queue
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;


class Solution_648{
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int begin = 0;
        bool to_replace;
        vector<string> vect_words;
        for (int i=0; i<sentence.size(); i++){
            if (sentence[i]==' '){
                vect_words.push_back(sentence.substr(begin, i-begin));
                begin = i + 1; 
            }
        }
        vect_words.push_back(sentence.substr(begin, sentence.size()-begin));

        for (auto & dict_item:dictionary){
            size_t found = sentence.find(dict_item);
            while (found!=std::string::npos){
                to_replace = false;
                if (found ==0){
                    to_replace = true;
                }else{
                    if (sentence[found-1] ==' ') to_replace =true;
                }
                if (to_replace){  // or this is the first element
                    size_t found_ind = sentence.find(' ', found +1); // if it is at the end,  it will be npos
                    sentence.replace(found,found_ind-found,dict_item);   
                } 
                found = sentence.find(dict_item, found +1);
            }
            
        }
        return sentence;
    }
};

int main(){
    Solution_648 sol_test;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    sol_test.replaceWords(dictionary, sentence); //(4,1,3);
    return 0;
}

