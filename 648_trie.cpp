#include<iostream>
#include<vector>
#include <queue>          // std::queue
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;

class Trie {
    public:
        Trie *child[26];
        bool last;
        Trie(){
            last = false;
            for (int i=0; i<26; i++){
                child[i] = NULL;
            }
        }
        ~Trie(){
            for (int i=0; i<26; i++){
                if (child[i]){
                    delete child[i];
                }
            }
        }
};
class Solution_648{
    Trie* trie_run = new Trie();
public:
    void insertword(string word){
        Trie* ptr_trie = trie_run;
        for (char c:word){
            int idx = c-'a';
            if (!ptr_trie->child[idx]){  // if child does not exist yet
                ptr_trie->child[idx] = new Trie();
            }
            ptr_trie = ptr_trie->child[idx];
        }
        ptr_trie->last = true;
    }
    string findroot(string word){
        Trie* ptr_trie = trie_run;
        string prefix = "";
        for(char c:word){
            int idx = c-'a';
            if(!ptr_trie->child[idx]){
                return word;
            }
            prefix+=c;
            ptr_trie = ptr_trie->child[idx];
            if (ptr_trie->last){
                return prefix;
            }
        }
        return word;
    }


    string replaceWords(vector<string>& dictionary, string sentence) {
        string word_send="";
        string res="";
        for (string word:dictionary){
            insertword(word);
        }
        for (char c: sentence){
            if ( c == ' '){
                res += findroot(word_send);
                res += ' ';
                word_send = "";
            }else{
                word_send +=c;
            }
        }
        // last word
        res += findroot(word_send);
        return res;
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

