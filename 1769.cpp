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
    vector<int> minOperations(string boxes) {
        vector<int> indices;
        vector<int> result;
        for(int i=0; i<boxes.size(); i++){
            if (boxes[i] == '1') {
                indices.push_back(i);
            }
        }
        for (int j=0; j<boxes.size(); j++){
            int sum = 0;
            for(int k=0; k<indices.size(); k++){
                sum+=abs(indices[k]-j);
            }
            result.push_back(sum);
        }
        return result;
        
    }
};

int main(){
    Solution s_test;
    string box = "110";
    vector<int> res = s_test.minOperations(box); //(4,1,3);
    return 0;
}