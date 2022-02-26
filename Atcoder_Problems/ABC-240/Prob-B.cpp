#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin>>N;
    set<int> s;
    for(int i=0;i<N;++i) {
        int val; cin>>val;
        s.insert(val);
    }
    cout<<s.size()<<endl;
}