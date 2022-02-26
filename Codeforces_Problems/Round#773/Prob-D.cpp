#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> queries; //stores are operations
vector<ll> seg; //stores length of all sug-segments

vector<ll> solve(vector<ll> cur, ll &offset) {
    vector<ll> rem;
    ll N = cur.size();
    ll breakpoint = 0;
    for(ll i=1;i<N;++i) {
        if((cur[i] == cur[0]) && (!breakpoint)) {
            breakpoint = i;
        }
        else if(breakpoint) {
            rem.push_back(cur[i]);
        }
    }
    assert(breakpoint > 0); //already handled in impossible case
    reverse(rem.begin(), rem.end());
    for(ll i=1;i<breakpoint;++i) {
        queries.push_back({breakpoint + i + offset, cur[i]});
        rem.push_back(cur[i]);
    }
    seg.push_back(2*breakpoint);
    offset += seg.back();
    reverse(rem.begin(), rem.end());
    
    return rem;
}

bool isValid(vector<ll> v) {
    ll N = v.size();
    map<ll,ll> mp;
    for(int val: v) mp[val]++;
    for(auto it: mp) {
        if(it.second % 2) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T; cin>>T;
    while(T--) {
        queries.clear();
        seg.clear();
        
        ll N; cin>>N;
        vector<ll> v;
        for(ll i=0;i<N;++i) {
            ll val; cin>>val;
            v.push_back(val);
        }
        
        //impossible case
        if(!isValid(v)) {
            cout<<-1<<endl;
            continue;
        }

        ll offset = 0;
        ll count = 0;
        while(!v.empty()) {
            ll L = v.size();
            v = solve(v, offset);
        }

        //printing the output
        cout<<queries.size()<<endl;
        for(pair<ll,ll> p: queries) {
            cout<<p.first<<" "<<p.second<<endl;
        }
        cout<<seg.size()<<endl;
        for(int len: seg) {
            cout<<len<<" ";
        }
        cout<<endl;
    }
}