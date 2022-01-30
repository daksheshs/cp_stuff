#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(true) {
            bool is_present = false;
            for(int num: nums) {
                if(num == original) {
                    is_present = true;
                    break;
                }
            }
            if(!is_present)
                break;
            original *= 2;
        }
        
        return original;
    }
};