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

class Solution_720{
    Trie* trie_run = new Trie();
    public:
        string longestWord(vector<string>& words) {
            int ind, j, found_index=-1;
            int count = 0;
            string found_word;
            sort(words.begin(), words.end());
            for (int i=0; i<words.size(); i++){
                Trie* trie_ptr = trie_run;  // back to trie_run for each new word
                int size_word = words[i].size();
                if (size_word == 1){
                    ind = words[i][0] - 'a'; // it is only one char
                    if (!trie_ptr->child[ind]){
                        trie_ptr->child[ind] = new Trie();
                    }
                    if (count<size_word){
                        count = size_word;
                        found_index = i;
                    }
                }else{  // size is more than 1, since it is sorted, the root should be already found in the trie
                    j= 0;

                    while(j<size_word-1){
                        ind = words[i][j] - 'a';
                        if (!trie_ptr->child[ind]){
                            break;
                        }
                        j++;
                        trie_ptr = trie_ptr->child[ind];
                    }
                    if (j==size_word-1){
                        ind = words[i][j] - 'a';
                        trie_ptr->child[ind] = new Trie();
                        if (count<size_word){
                            count = size_word;
                            found_index = i;
                        }
                    }
                }
            }
            if (found_index == -1) return "";
            else return words[found_index];
        }
};

int main(){
    Solution_720 sol_test;
    vector<string> words_list = {"l","le","lel","lelelele"}; //{"a","banana","app","appl","ap","apply","apple"};
    string res = sol_test.longestWord(words_list); //(4,1,3);
    return 0;
}

