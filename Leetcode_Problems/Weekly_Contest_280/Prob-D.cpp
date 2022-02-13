#include <bits/stdc++.h>
using namespace std;
const int MINN = -1e5;

class Solution {
public:
    // Time Complexity: O(3^m * n * m) where n = array size, m = slot size,
    // Space Complexity: O(3^m), Optimised space to 1D dp array
    // State: dp(i, mask) => max AND Sum of array ending at i, with "mask" representation of slots being occupied till now
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int N = nums.size();
        int dp[(int)pow(3, numSlots)];
        int ans = MINN;
        for(int mask=0;mask < pow(3, numSlots);++mask) {
            dp[mask] = MINN;
        }
        
        //base case
        for(int bit=0;bit<numSlots;bit++) {
            dp[(int)pow(3, bit)] = (bit + 1) & nums[0];
            ans = max(ans, (bit + 1) & nums[0]);
        }
        
        for(int j=1;j<N;++j) {
            int temp[(int)pow(3, numSlots)];
            for(int mask=0;mask<pow(3, numSlots);++mask)
                temp[mask] = dp[mask];
            
            for(int mask=0;mask<pow(3, numSlots);++mask) {
                dp[mask] = MINN;
                // base-3 representation
                // eg: 10201 = 1*3^0 + 0 * 3^1 + 2 * 3^2 + ....
                int copy_mask = mask;
                for(int i=0;i<numSlots;++i) {
                    int value = copy_mask % 3;
                    if(value && (mask >= pow(3, i)) && (temp[mask - (int)pow(3, i)] >= 0)) {
                        dp[mask] = max(dp[mask], temp[mask - (int)pow(3, i)] + ((i + 1) & nums[j]));
                    }
                    copy_mask = copy_mask/3;
                }
                if(j == N - 1)
                    ans = max(ans, dp[mask]);
            }
        }
        return ans;
    }
};