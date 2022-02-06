#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    string s; cin>>s;
    deque<int> dq;
    bool lastL = false;
    bool lastR = false;
    for(int i=N;i>0;--i) {
        if((s[i - 1] == 'L') && !lastL) {
            dq.push_front(i);
            lastR = false;
            lastL = true;
        }
        else if(s[i - 1] == 'L') {
            dq.push_back(i);
        }
        else if((s[i - 1] == 'R') && !lastR) {
            dq.push_back(i);
            lastL = false;
            lastR = true;
        }
        else {
            dq.push_front(i);
        }
    }

    if(s[0] == 'L') dq.push_back(0);
    else dq.push_front(0);

    while(!dq.empty()) {
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}
