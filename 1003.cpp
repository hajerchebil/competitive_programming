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
    bool isValid(string s) {
        stack<char> st;
        if (s[0] != 'a') return false;
        for (char &c: s){
            if (c=='c' && !st.empty() && st.top()=='b'){
                st.pop();
                if (!st.empty() && st.top()=='a'){
                    st.pop();
                }else{
                    return false;
                }
            }
            else if (c=='b' || c=='a'){
                st.push(c);
            }else{
                return false;
            }
        }
        if (st.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution s_test;
    string s = "abccba";
    bool res = s_test.isValid(s); //(4,1,3);
    return 0;
}