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
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1; // distance between 2 balls is one
        int high = ceil(position[position.size()-1] /(m-1));
        int mid;
        int ans;
        bool res;
        while(low<=high){
            mid = low + (high - low) /2;
            res = check_balls(position, mid, m);
            if (res) 
            {
                low = mid +1;
                ans= mid;
            }
            else high = mid-1;
        }
        return ans;
    }
private:
    bool check_balls(vector<int>& position, int distance, int balls){
        int curr_pos = position[0];
        int count_balls = 1;
        for (int i=1; i<position.size(); i++){
            if ((position[i] - curr_pos) >= distance){
                count_balls++;
                curr_pos = position[i];
            }
            if (count_balls>= balls) break;

        }
        if (count_balls>= balls) return true;
        else return false;
    }
};



int main(){
    Solution s_test;
    vector<int> s = {5,4,3,2,1,1000000000};
    int m = 2;
    int res = s_test.maxDistance(s, m); //(4,1,3);
    return 0;
}