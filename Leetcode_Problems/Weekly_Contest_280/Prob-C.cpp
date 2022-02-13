#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long N = beans.size();
        sort(beans.begin(), beans.end());
        long long sum = 0;
        long long total_sum = accumulate(beans.begin(), beans.end(), 0LL);
        long long ans = LLONG_MAX;
        for(long long i=0;i<N;++i) {
            sum += beans[i];
            ans = min(ans, total_sum - (long long)(beans[i] * (N - i)));
        }
        
        return ans;
    }
};