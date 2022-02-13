#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int N = nums.size();
        map<int,int> freq1;
        map<int,int> freq2;
        for(int i=0;i<N;++i) {
            if(i%2) freq2[nums[i]]++;
            else freq1[nums[i]]++;
        }
        
        int max1 = 0;
        int smax1 = 0;
        int max_value1 = 0;
        int max2 = 0;
        int smax2 = 0;
        int max_value2 = 0;
        int len1 = (N + 1)/2;
        int len2 = N/2;
        for(auto it: freq1) {
            if(max1 < it.second) {
                smax1 = max1;
                max1 = it.second;
                max_value1 = it.first;
            }
            else if(max1 == it.second) {
                smax1 = max1;
            }
            else if(smax1 < it.second) {
                smax1 = it.second;
            }
        }
        
        for(auto it: freq2) {
            if(max2 < it.second) {
                smax2 = max2;
                max2 = it.second;
                max_value2 = it.first;
            }
            else if(max2 == it.second) {
                smax2 = max2;
            }
            else if(smax2 < it.second) {
                smax2 = it.second;
            }
        }
        
        if(max_value1 == max_value2) {
            return min(len1 - max1 + len2 - smax2, len1 - smax1 + len2 - max2);
        }
        
        return (len1 - max1 + len2 - max2);
    }
};