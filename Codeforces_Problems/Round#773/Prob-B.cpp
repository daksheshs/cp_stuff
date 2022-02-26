#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T; cin>>T;
    while(T--) {
        ll N; cin>>N;
        set<ll> s;
        for(ll i=0;i<N;++i) {
            ll val; cin>>val;
            s.insert(val);
        }
        ll M = s.size();

        for(ll k=1;k<=N;++k) {
            cout<<max(k, M)<<" ";
        }
        cout<<endl;
    }
}