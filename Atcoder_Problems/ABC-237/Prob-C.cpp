#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin>>s;
    int N = s.length();
    int pre_a = 0;
    int suff_a = 0;

    for(int i=0;i<N;++i) {
        if(s[i] != 'a')
            break;
        pre_a++;
    }

    for(int i=(N - 1);i>=0;--i) {
        if(s[i] != 'a')
            break;
        suff_a++;
    }

    if(pre_a > suff_a) {
        cout<<"No"<<endl;
        return 0;
    }

    int to_remove = suff_a - pre_a;
    string cur = s.substr(0, N - to_remove);

    int M = cur.size();
    bool is_palindrome = true;
    for(int i=0;i<M/2;++i) {
        if(s[i] != s[M - i - 1]) {
            is_palindrome = false;
            break;
        }
    }
    
    if(is_palindrome) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}