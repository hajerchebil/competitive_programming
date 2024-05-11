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
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        // priority queue created as a min heap
        //priority_queue <int, vector<int>, greater<int>> pq;
        map<char, priority_queue <int, vector<int>, greater<int>>> mp;
        priority_queue <int, vector<int>, greater<int>> pq;
        int counter = 0;
        int max_val;
        for (int i=0; i<s.size(); i++){
            max_val = max(abs(points[i][0]), abs(points[i][1]));
            mp[s[i]].push(sqrt(2*pow(max_val,2)));
        }
        // ierate through the map and get the min
        vector<int> first_elements;
        vector<int> second_elements;
        int min_ele=INT_MAX;
        for (auto it = mp.begin(); it != mp.end(); ++it){
            pq = it->second;
            first_elements.push_back(pq.top());
            pq.pop();
            if (!pq.empty())
                second_elements.push_back(pq.top());
        }
        if (second_elements.size()>0)
            min_ele = *min_element(second_elements.begin(), second_elements.end());
        for (int i=0; i<first_elements.size(); i++){
            if (first_elements[i] < min_ele) counter++;
        }
        return counter;
    }
};

int main(){
    Solution s_test;
    vector<vector<int>> vect = {{1,-1}}; //{{2,2},{-1,-2},{-4,4},{-3,1},{3,-3}};  //{{1,0,2},{1,0,2}};
    string s = "a";
    bool res = s_test.maxPointsInsideSquare(vect,s); //(4,1,3);
    return 0;
}
