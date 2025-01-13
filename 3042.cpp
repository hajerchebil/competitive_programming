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
    int countPrefixSuffixPairs(vector<string>& words) {
        int len_str = 0;
        int len_curr = 0;
        int counter=0;
        sort(words.begin(), words.end(), 
            [](const string &a, const string &b){return a.length()<b.length();});
        
        for(int i=0; i<words.size()-1; i++){
            for (int j=i+1; j<words.size(); j++){
                len_str = words[i].size();
                len_curr = words[j].size();
                if ((words[j].substr(0, len_str)==words[i])&&
                    (words[j].substr(len_curr-len_str, len_str))== words[i]){
                        counter ++;
                    }
            }
        }
        return counter; 
    }
};

int main(){
    Solution s_test;
    vector<string> s = {"pa","papa","ma","mama"};
    int res = s_test.countPrefixSuffixPairs(s); //(4,1,3);
    return 0;
}