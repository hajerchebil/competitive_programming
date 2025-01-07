#include<iostream>
#include<vector>
#include <queue>          // std::queue
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        vector<string> vect_res;

        std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
            return a.length() < b.length();
        });

        for (int i=0; i<words.size(); i++){
            for (int j=words.size()-1;j>i; j--){
                if (words[j].find(words[i]) != string::npos){
                    vect_res.push_back(words[i]);
                }
            }
        }

        return vect_res;
    }
};


int main(){
    Solution s_test;
    vector<string> s = {"is","ylisia","exd","aiexd"};
    vector<string> res = s_test.stringMatching(s); //(4,1,3);
    return 0;
}