#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M; cin>>N>>M;
    int mat[N][M];
    int tr_mat[M][N];

    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            cin>>mat[i][j];
        }
    }
    
    //rotate the matrix
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            tr_mat[j][i] = mat[i][j];
        }
    }

    for(int i=0;i<M;++i) {
        for(int j=0;j<N;++j) {
            cout<<tr_mat[i][j]<<" ";
        }
        cout<<endl;
    }
}