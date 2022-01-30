#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    ll power(ll x, ll p, ll m) {
        ll res = 1LL;
        while(p) {
            if(p%2) res = (res * x) % m;
            p /= 2LL;
            x = (x * x) % m;
        }
        return res;
    }
    
    string subStrHash(string s, int p, int m, int k, int hashValue) {
        //Going right-to-left
        // Relation: H(i - 1) = ((H(i) - value(s[i + k]) * p^(k - 1)) * p + value(s[i - 1])) % m
        ll N = s.length();
        ll ans = 0;
        for(ll i=(N - 1);i>=(N - k);--i) {
            ans = ((ans * p) % m + (s[i] - 'a' + 1LL) % m) % m;
        }
        
        // 0,1,2,3,4,5
        // k = 3, N = 6
        
        ll start = -1;
        if(ans == hashValue)
            start = N - k;
        
        for(ll i=(N - k - 1);i>=0;--i) {
            ll cur_ans = (ans - (power(p, k - 1, m) * (s[i + k] - 'a' + 1LL)) % m + m) % m;
            cur_ans = (cur_ans * p) % m;
            cur_ans += (s[i] - 'a' + 1);
            cur_ans %= m;
            if(hashValue == cur_ans) {
                start = i;
            }
            ans = cur_ans;
        }
        
        return s.substr(start, k);
    }
};