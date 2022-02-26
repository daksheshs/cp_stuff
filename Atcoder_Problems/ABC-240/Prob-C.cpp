#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10105

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N,X; cin>>N>>X;
    ll dp[X + 1] = {};
    ll A[N], B[N];
    for(ll i=0;i<N;++i) {
        cin>>A[i]>>B[i];
    }
    
    //base case
    dp[0] = 1;
    for(ll j=1;j<=N;++j) {
        int temp[X + 1];
        for(int i=0;i<=X;++i) {
            temp[i] = dp[i];
        }
        
        dp[0] = 0;
        for(ll i=1;i<=X;++i) {
            dp[i] = 0;
            if(i >= A[j - 1]) dp[i] = dp[i] | temp[i - A[j - 1]];
            if(i >= B[j - 1]) dp[i] = dp[i] | temp[i - B[j - 1]];
        }
    }
    
    if(dp[X]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}