#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);   
    }

    long long countPairs(vector<int>& nums, int k) {
        int mp[MAXN] = {};
        for(int val: nums) {
            mp[val]++;
        }
        int mult[MAXN] = {0};
        for(int i=1;i<MAXN;++i) {
            for(int j=i;j<MAXN;j+=i) {
                mult[i] += mp[j];
            }
        }
        
        long long ans = 0;
        for(int i=1;i<MAXN;++i) {
            if(mp[i] == 0) continue;
            
            long long val = i;
            long long freq = mp[val];
            long long g = gcd(val, k);
            k /= g;
            
            //number of mutiples of k
            if(val % k == 0) {
                ans += freq * (freq - 1);
                ans += freq * (mult[k] - freq);
            }
            else 
                ans += freq * mult[k];
            k *= g; //restore k
        }
        ans /= 2LL;
        
        return ans;
    }
};