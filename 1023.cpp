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
        Trie* child[60]; // this time we have upper & lower cases
        bool last=false;
        Trie(){
            last;
            for (int i=0; i<60; i++){
                child[i] = NULL;
            }
        }
        ~Trie(){
            for(int i=0; i<60; i++){
                if (child[i]){
                    delete child[i];
                }
            }
        }
};

class Solution_1023{
    Trie* trie_run = new Trie();
    public:
        vector<bool> camelMatch(vector<string>& queries, string pattern) {
            Trie* ptr_trie = trie_run;
            vector<bool> ans;
            int ind;
            bool res;
            for (char c:pattern){
                ind = c - 'A';
                if (!ptr_trie->child[ind]){
                    ptr_trie->child[ind] = new Trie();
                }
                ptr_trie = ptr_trie->child[ind];
            }
            ptr_trie->last = true;
            /// go through all queries
            for (string query: queries){
                ptr_trie = trie_run;
                res = true;
                for(char c: query){
                    ind = c-'A';
                    if (ptr_trie->child[ind]) ptr_trie = ptr_trie->child[ind];
                    else if (isupper(c))
                    {
                        res = false;
                    }
                }
                if (!ptr_trie->last) res = false;
                ans.push_back(res);
            }
            return ans;
        }
};

int main(){
    Solution_1023 sol_test;
    vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};  //{"/a","/a/b","/c/d","/c/d/e","/c/f"};
    string pattern = "FoBaT"; 
    sol_test.camelMatch(queries, pattern); //(4,1,3);
    return 0;
}

