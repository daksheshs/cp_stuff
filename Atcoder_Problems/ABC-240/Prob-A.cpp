#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A,B; cin>>A>>B;
    if(A > B) swap(A, B);
    if(B - A == 1 || B - A == 9) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}