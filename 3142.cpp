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
    bool satisfiesConditions(vector<vector<int>>& grid) {
        bool res=true;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size()-1; j++){
                if(grid[i][j] == grid[i][j + 1]) return false;
            }
        }



        for(int i=0; i<grid.size()-1; i++){
            for(int j=0; j<grid[0].size()-1; j++){
                if ((grid[i][j]!=grid[i+1][j])||(grid[i][j]==grid[i][j+1])||(grid[grid.size()-1][j] == grid[grid.size()-1][j+1])){
                    res = false;
                    j = grid[0].size();
                    i = grid.size();
                }
            }
            if (res){
                if (grid[i][grid[0].size()-1]!=grid[i+1][grid[0].size()-1]){
                    res = false;
                    i = grid.size();
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s_test;
    vector<vector<int>> vect = {{1,1,6,1,4,6,3,1,0,7}};  //{{1,0,2},{1,0,2}};
    bool res = s_test.satisfiesConditions(vect); //(4,1,3);
    return 0;
}
