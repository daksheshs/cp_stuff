#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N; cin>>N;
    ll L = -1LL * (1LL << 31);
    ll R = (1LL << 31) - 1;
    if(N >= L && N <= R) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}