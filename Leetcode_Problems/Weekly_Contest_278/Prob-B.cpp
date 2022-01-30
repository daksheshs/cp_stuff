#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int N = nums.size();
        int zeroes_left = 0;
        for(int num: nums) {
            if(num == 0) zeroes_left++;
        }
        
        vector<int> indices;
        int max_score = zeroes_left;
        indices.push_back(N);
        int ones_till_now = 0;
        for(int i=(N - 1);i>=0;--i) {
            if(nums[i]) ones_till_now++;
            else zeroes_left--;
            
            int score = zeroes_left + ones_till_now;
            if(max_score < score) {
                indices.clear();
                indices.push_back(i);
                max_score = score;
            }
            else if(max_score == score) {
                indices.push_back(i);
            }
        }
        
        return indices;
    }
};