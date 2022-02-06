//cool problem!!!
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e8;

class Solution {
public:
    int minimumTime(string s) {
        int N = s.length();
        int dp[N][3]; //min ans ending at i
        // type-1: when removed from either ends, adds 1 to the cost
        // type-2: when removed from anywhere, adds 2 to the cost for "1", else 0
        // States: 
        // dp[i][0] = min ans ending at i, if we take all through type-1
        // dp[i][1] = min ans ending at i, if we use type-2 for atleast +ve time and then type-1 for some time(maybe 0)
        // dp[i][2] = min ans ending at i, if we use type-1 for atleast +ve time and then anyone of the above 2 states
        
        //base case
        dp[0][0] = 1;
        dp[0][1] = ((s[0] == '1') ? 2 : 0);
        dp[0][2] = MAX;
        for(int i=1;i<N;++i) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = ((s[i] == '1') ? 2 : 0) + min(dp[i - 1][1], dp[i - 1][0]);
            dp[i][2] = 1 + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        }
        
        return min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
    }
};