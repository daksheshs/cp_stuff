#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
map<ll,ll> dp;

ll solve(ll X) {
    if(X <= 4) return X;
    if(dp.find(X) != dp.end())  return dp[X];

    ll a = solve((X + 1)/2);
    ll b = solve(X/2);

    dp[X] = (a * b) % MOD;
    return dp[X];
}

int main() {
    ll X; cin>>X;
    cout<<solve(X)<<endl;
}