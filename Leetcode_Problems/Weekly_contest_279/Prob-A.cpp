#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            if(i%2) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        int odd_ptr = 0; //ptr to odd indices
        int even_ptr = 0; //ptr to even indices
        for(int i=0;i<nums.size();++i) {
            if(i%2) ans.push_back(odd[odd_ptr++]);
            else ans.push_back(even[even_ptr++]);
        }
        
        return ans;
    }
};