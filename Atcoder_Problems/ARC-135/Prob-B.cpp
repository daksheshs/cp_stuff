#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Seq: a,b,c, a + s[1] - s[0], b + s[2] - s[1], c + s[3] - s[2] 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    ll S[N];
    for(ll i=0;i<N;++i)
        cin>>S[i];

    ll maxx[3] = {0}; 
    ll sum[3] = {0};
    ll ans[N + 2];
    for(ll i=0;i<(N + 2);++i) {
        sum[i % 3] += ((i >= 3) ? (S[i - 2] - S[i - 3]) : 0);
        ans[i] = sum[i % 3];
        if(sum[i % 3] < 0)
            maxx[i % 3] = max(maxx[i % 3], abs(sum[i % 3]));
    }

    if(maxx[0] + maxx[1] + maxx[2] <= S[0]) {
        cout<<"Yes"<<endl;
        ll diff = S[0] - maxx[0] - maxx[1] - maxx[2];
        for(int i=0;i<(N + 2);i++) {
            ans[i] += maxx[i % 3];
            if(i%3 == 0) ans[i] += diff;
            assert(ans[i] >= 0);
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    
}