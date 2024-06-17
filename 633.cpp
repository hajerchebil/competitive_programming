#include<iostream>
#include<vector>
#include <queue>
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;
class Trie{
    public:
        Trie* child[26];
        bool last;
        Trie(){
            last = false;
            for (int i=0; i<26; i++){
                child[i] = NULL;
            }
        }
        ~Trie(){
            for (int i=0; i<26; i++){
                if(child[i]){
                    delete child[i];
                }
            }
        }

};

class Solution_633{
    public:
        bool judgeSquareSum(int c) {
            int low = 0;
            int high = sqrt(c);
            long temp_sum;
            while(low<=high){
                temp_sum = pow(low, 2) + pow(high, 2);
                if ( temp_sum == c){
                    return true;
                }
                if (temp_sum>c){
                    high --;
                }else{ // temp_sum<c
                    low ++;
                }
                //high --;
                //low ++;
            }
            return false;
        }
};

int main(){
    Solution_633 sol_test;
     //{"/a","/a/b","/c/d","/c/d/e","/c/f"};
    int c = 2147482647;
    sol_test.judgeSquareSum(c); //(4,1,3);
    return 0;
}

