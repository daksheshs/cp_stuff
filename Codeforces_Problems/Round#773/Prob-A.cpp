#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T; cin>>T;
    while(T--) {
        ll X[3],Y[3];
        for(ll i=0;i<3;++i) {
            cin>>X[i]>>Y[i];
        }
        
        long double ans = 0.0;
        //parallel lines to x-axis
        if((Y[0] == Y[1]) && (Y[0] > Y[2])) {
            ans += (double)abs(X[0] - X[1]);
        }
        else if((Y[0] == Y[2]) && (Y[0] > Y[1])) {
            ans += (double)abs(X[0] - X[2]);
        }
        else if((Y[1] == Y[2]) && (Y[1] > Y[0])) {
            ans += (double)abs(X[1] - X[2]);
        }

        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}