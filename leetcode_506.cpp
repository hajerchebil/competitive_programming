#include<iostream>
#include<vector>
#include <queue>          // std::queue
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;

class Solution_506 {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int index;
        int counter = 1;
        vector<string> result(score.size());
        while(counter<=score.size()){
            index = max_element(score.begin(), score.end()) - score.begin();
            if (counter==1)
                result[index] = "Gold Medal";
            else if (counter==2)
                result[index] = "Silver Medal";
            else if (counter==3)
                result[index] = "Bronze Medal";
            else
                result[index] = to_string(counter);
            score[index] = -1;
            counter++;
        }

        return result;
    }
};



int main(){
    Solution_506 s_test;
    vector<int> test_matrix = {10,3,8,9,4};

    vector<string> res = s_test.findRelativeRanks(test_matrix); //(4,1,3);
    return 0;
}
