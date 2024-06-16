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
        Trie* child[26]; // consists only of lower cases
        bool last=false;
        Trie(){
            last;
            for (int i=0; i<26; i++){
                child[i] = NULL;
            }
        }
        ~Trie(){
            for(int i=0; i<26; i++){
                if (child[i]){
                    delete child[i];
                }
            }
        }
};

class Solution_820{
    Trie* trie_run = new Trie();
    public:
        void display(Trie* trie_print, int level, char word_trie[], int& count){
            if(trie_print->last){
                count += level + 1;
                return;
            }
            for(int i=0;i<26; i++){
                if (trie_print->child[i]){
                    word_trie[level] = i + 'a';
                    level ++;
                    display(trie_print->child[i], level, word_trie, count);
                    level --;
                }
            }
        }
        int minimumLengthEncoding(vector<string>& words) {
            int ind;
            bool exists;
            for (string word:words){
                Trie* ptr_trie = trie_run;
                exists =true;
                for (int i = word.size()-1; i>=0; i--){
                    ind = word[i] - 'a';
                    if (!ptr_trie->child[ind]){
                        ptr_trie->child[ind] = new Trie();
                        exists = false; // we use exists to track if it is a substring or not
                    }
                    ptr_trie ->last = false; // we need to set  it again to false because we need the longer word
                    ptr_trie = ptr_trie->child[ind];
                }
                if (!exists){
                    ptr_trie->last = true;
                }
            }
            ////////////////////////////////////////////
            // display the added
            int count = 0;
            char word_trie[7];
            Trie* ptr_trie_ptr = trie_run;
            display(ptr_trie_ptr, 0, word_trie, count);
            return count;
        }
};

int main(){
    Solution_820 sol_test;
    vector<string> words = {"me", "time"};  //{"/a","/a/b","/c/d","/c/d/e","/c/f"};
    sol_test.minimumLengthEncoding(words); //(4,1,3);
    return 0;
}

