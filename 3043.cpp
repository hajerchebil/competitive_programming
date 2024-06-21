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
        Trie* child[10];
        bool last;
        Trie(){
            last = false;
            for (int i=0; i<10; i++){
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

class Solution_3043{
    Trie* trie_run = new Trie();
    public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int div, rem;
        Trie* ptr_trie;
        // insertion of data in the trie
        int count, max_count = 0;
        for (int i:arr1){
            ptr_trie = trie_run;
            ////////////////
            int divisor = 1;
            while (i / divisor >= 10) {
                divisor *= 10;
            }

            // Extract and print each digit starting from the highest
            while (divisor > 0) {
                int digit = i / divisor;
                if (!ptr_trie->child[digit]){
                    ptr_trie ->child[digit] = new Trie();
                }
                ptr_trie = ptr_trie->child[digit];
                i %= divisor;
                divisor /= 10;
            }
            ptr_trie ->last = true;
        }

        // search for the prefix by going through arr2
        for (int i: arr2){
            ptr_trie = trie_run;
            count = 0;
            //////////////////////////////////////////
            int divisor = 1;
            while (i / divisor >= 10) {
                divisor *= 10;
            }

            // Extract and print each digit starting from the highest
            while (divisor > 0) {
                int digit = i / divisor;
                if (!ptr_trie->child[digit]){
                    break;
                }
                ptr_trie = ptr_trie->child[digit];
                i %= divisor;
                divisor /= 10;
                count ++;
            }
            max_count = max(count, max_count);
        }
        return max_count;

    }    
};

int main(){
    Solution_3043 sol_test;
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {4,4,4};
    int res = sol_test.longestCommonPrefix(arr1, arr2); //(4,1,3);
    return 0;
}

