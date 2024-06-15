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
        Trie* child[27]; // each trie can point to any of the 26 children
        bool last=false;
        Trie(){
            last;
            for (int i=0; i<27; i++){
                child[i] = NULL;
            }
        }
        ~Trie(){
            for(int i=0; i<27; i++){
                if (child[i]){
                    delete child[i];
                }
            }
        }
};

class Solution_1233{
    Trie* trie_run = new Trie();
    public:
        vector<string> removeSubfolders(vector<string>& folder) {
            int ind;
            for (string fold:folder){
                Trie* ptr_trie = trie_run;
                for (char c:fold){
                    if (c=='/') ind = 0;
                    else ind = c - 'a' + 1;
                    if (!ptr_trie->child[ind]){
                        ptr_trie->child[ind] = new Trie();
                    }
                    ptr_trie = ptr_trie->child[ind];
                }
                ptr_trie->child[0] = new Trie(); // index 0 is the '/' at the end
                ptr_trie = ptr_trie->child[0];
                ptr_trie->last = true;
            }
            char word[100] = {0};
            vector<string> word_list = {};
            display(trie_run, 0, word, word_list);
            return word_list;
        }
        void display(Trie* ptr_trie, int level, char word[], vector<string>& word_list){
            if (ptr_trie == NULL) return;
            if (ptr_trie->last){
                word[level] = '\0';
                string temp = "";
                for (int i=0; i<level-1; i++){ // level-1 because we want to ignore the last /
                    temp += word[i];
                }
                word_list.push_back(temp);
                return;
            }


            for (int i=0; i<27; i++){

                if (ptr_trie->child[i]){
                    if (i == 0) word[level] = '/';
                    else word[level] = (i - 1) + 'a';
                    level ++;
                    display(ptr_trie->child[i], level, word, word_list);
                    level --; // tres important: make level back to previous value
                }            
            }
        }
};

int main(){
    Solution_1233 sol_test;
    vector<string> folder = {"/a/b/c","/a/b/ca","/a/b/d"};  //{"/a","/a/b","/c/d","/c/d/e","/c/f"};
    sol_test.removeSubfolders(folder); //(4,1,3);
    return 0;
}

