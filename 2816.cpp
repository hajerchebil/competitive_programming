#include<iostream>
#include<vector>
#include <queue>          // std::queue
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_2816 {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        int value;
        stack<int> st;
        int carry = 0;
        while (curr!=nullptr){
            st.push(curr->val);
            curr = curr->next;
        }
        ListNode* Tail = nullptr;
        carry = 0;
        while(!st.empty()){
            value = st.top()*2;
            Tail = new ListNode(0, Tail);
            Tail->val = value%10 + carry;
            carry = value / 10;
            st.pop();
        }
        if (carry!=0){
            Tail = new ListNode(0, Tail);
            Tail->val = carry;

        }    
        return Tail;

    }
};

int main(){
    Solution_2816 s_test;
    // Create the nodes
    ListNode *head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);

    ListNode* res = s_test.doubleIt(head); //(4,1,3);
    return 0;
}
