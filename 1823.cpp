#include<iostream>
#include<vector>
#include <queue>          // std::queue
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;
class Solution_1823 {
public:
    int findTheWinner(int n, int k) {
        vector<int> myvect;
        for (int i = 1; i <= n; ++i) {
            myvect.push_back(i);
        }
        recursive_find(0, k, myvect);
        return myvect[0];
    }

private:
    void recursive_find(int num_index, int k_f, vector<int> & myvect){
        int to_remove;
        if (myvect.size()==1){
            return ;
        }
        to_remove = (num_index + k_f)%myvect.size() - 1;
        if (to_remove <=-1) to_remove += myvect.size();
        myvect.erase(myvect.begin() + to_remove);
        recursive_find(to_remove%myvect.size(), k_f, myvect);
    }
};

int main(){
    Solution_1823 s_test;
    int n = 6;
    int k = 5;
    int res = s_test.findTheWinner(n, k); //(4,1,3);
    return 0;
}
