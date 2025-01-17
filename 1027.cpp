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
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int val, index;
        int count = 0;
        int ans = 1;
        for(int i=0; i< nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        for (const auto& entry : mp) {

            for (int diff=-500; diff<=500; diff++ ){
                val = entry.first;
                index = entry.second[0];
                count = 1; 
                while(mp.find(val+diff) != mp.end()){
                    vector<int> &indices = mp[val+diff];
                    int found = binary_search(index, indices);
                    if (found == indices.size()) break;
                    index = indices[found];
                    val = nums[index];
                    count ++;
                }
                ans = max(ans, count);
            }
            
        }
        return ans;
    }
    int binary_search(int index, vector<int> indices){
        int l = 0;
        int r = indices.size();
        
        while(l<r){
            int mid = l + (r-l)/2;
            if (indices[mid]<= index){
                l = mid + 1 ;
            }else{
                r =mid;
            }
        }
        return l;
    }
};


int main(){
    Solution s_test;
    vector<int> s = {20,1,15,3,10,5,8};   //15,5
    int res = s_test.longestArithSeqLength(s); //(4,1,3);
    return 0;
}