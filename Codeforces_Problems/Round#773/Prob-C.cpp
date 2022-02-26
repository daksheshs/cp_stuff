#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T; cin>>T;
    while(T--) {
        ll N,X; cin>>N>>X;
        map<ll,ll> mp;
        for(ll i=0;i<N;++i) {
            ll val; cin>>val;
            mp[val]++;
        }

        ll ans = 0;
        for(auto it: mp) {
            ll val = it.first;
            ll req_val = val * X;
            ll freq = it.second;
            if(freq == 0) continue;
            
            ll take = 0;
            if(mp.find(req_val) != mp.end()) {
                take = min(freq, mp[req_val]);
                mp[req_val] -= take;
            }
            ans += freq - take;
        }
        
        cout<<ans<<endl;
    }
}