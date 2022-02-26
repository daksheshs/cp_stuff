#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200005
vector<ll> adj[MAXN];
pair<ll,ll> ans[MAXN];
ll global_max = 1;

void DFS(ll s, ll p) {
    ll minn = LLONG_MAX;
    ll maxx = LLONG_MIN;
    for(ll v: adj[s]) {
        if(v != p) {
            DFS(v, s);
            minn = min(minn, ans[v].first);
            maxx = max(maxx, ans[v].second);
        }
    }
    // cout<<s<<" "<<minn<<" "<<maxx<<endl;

    if(minn == LLONG_MAX) {
        ans[s].first = global_max;
        ans[s].second = global_max;
        global_max++;
    }
    else {
        ans[s].first = minn;
        ans[s].second = maxx;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N; cin>>N;
    for(ll i=1;i<N;++i) {
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    DFS(1, -1);

    for(ll i=1;i<=N;++i) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}