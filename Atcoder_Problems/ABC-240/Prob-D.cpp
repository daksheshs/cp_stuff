#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 10105

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N; cin>>N;
    stack<int> num;
    stack<int> freq;
    for(ll i=0;i<N;++i) {
        ll val; cin>>val;
        ll window = (freq.empty()) ? 0 : freq.top();
        if(!num.empty() && (num.top() == val)) window++;
        else window = 1;
        num.push(val);
        freq.push(window);
        if(val == window) {
            while(window) {
                assert(!num.empty());
                num.pop();
                freq.pop();
                window--;
            }
        }
        cout<<num.size()<<endl;
    }
}