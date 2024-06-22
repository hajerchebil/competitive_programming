#include<iostream>
#include<vector>
#include <queue>
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;


class Solution_1248{
    public:
        int numberOfSubarrays(vector<int>& nums, int k) {
            int count = 0;
            int j;
            vector<int> prefix_arr(nums.size()+1, 0);
            for (int i=0; i<nums.size(); i++){
                prefix_arr[i+1] = prefix_arr[i] + nums[i]%2;
            }
            j = prefix_arr.size()-1;
            for (int i=0; i<prefix_arr.size()-1; i++){
                while((j>i)&&(prefix_arr[j]-prefix_arr[i]>k)) j--;
                if (prefix_arr[j]-prefix_arr[i]==k){  
                    int l = j; 
                    while((l>i)&&(prefix_arr[l]-prefix_arr[i]==k)){
                        count ++;
                        l--;
                    }
                }
                while((j<prefix_arr.size()-1)&&(prefix_arr[j]-prefix_arr[i]-1<=k))  j++;  // j need to be incremented back because we will increment i
            }
            // the following code causes a time limit exception
            /*
            for (int i=0; i<prefix_arr.size()-1; i++){
                j = i + 1;
                while(prefix_arr[j]-prefix_arr[i]<k) j++;
                while(prefix_arr[j]-prefix_arr[i]==k){
                    count ++;
                    j++;
                }
                if (j>prefix_arr.size()-1) break;
            } */           

            /*
            for (int i=0; i<prefix_arr.size(); i++){
                int j = i +1 ;
                for (int j = i+1; j<prefix_arr.size(); j++){
                    if (prefix_arr[j]-prefix_arr[i] == k){
                        count ++;
                    }
                }
            } */
            return count;

        }
};

int main(){
    Solution_1248 sol_test;
    vector<int> nums_list = {45627,50891,94884,11286,35337,46414,62029,20247,72789,89158,54203,79628,25920,16832,47469,80909}; //{"a","banana","app","appl","ap","apply","apple"};
    int k = 1;
    int res = sol_test.numberOfSubarrays(nums_list, k); //(4,1,3);
    return 0;
}

