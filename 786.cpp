#include<iostream>
#include<vector>
#include <queue>          // std::queue
#include<map>
#include <numeric>
#include <algorithm> // Include the algorithm header
#include <bits/stdc++.h>
using namespace std;


// Custom comparator for ordering tuples based on the third value
struct CompareTuples {
    bool operator()(const std::tuple<int, int, double>& a, const std::tuple<int, int, double>& b) const {
        return std::get<2>(a) > std::get<2>(b);  // ascending order
    }
};

class Solution_786 {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> res;
        double val;
        priority_queue<tuple<int, int, double>, vector<tuple<int, int, double>>, CompareTuples> pq;
        for(int i=0; i<arr.size()-1; i++){
            for (int j=i+1; j<arr.size(); j++){
                pq.push(make_tuple(arr[i], arr[j], static_cast<double>(arr[i])/arr[j]));
            }
        }
        for (size_t i = 0; i < k-1; ++i) {
            tuple<int, int, double> res_tuple = pq.top();
            pq.pop(); // Remove elements until the desired position
        }
        tuple<int, int, double> res_tuple = pq.top();
        res.push_back(get<0>(res_tuple));
        res.push_back(get<1>(res_tuple));
        return res;
    }
};


int main(){
    Solution_786 s_test;
    vector<int> test_matrix = {1,2,3,5};  //{1,7,23,29,47};
    int k = 3;
    vector<int> res = s_test.kthSmallestPrimeFraction(test_matrix, k); //(4,1,3);
    return 0;
}
