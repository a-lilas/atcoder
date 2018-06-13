#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

int main(){
    int N, C; cin >> N >> C;
    int D[C+1][C+1];
    int c[N+1][N+1];
    int m[3][C+1];
    memset(m, 0, sizeof(m));

    FOR(i, 1, C+1) FOR(j, 1, C+1) cin >> D[i][j];
    FOR(i, 1, N+1) FOR(j, 1, N+1){
        cin >> c[i][j];
        m[(i+j)%3][c[i][j]]++;
    }

    int mind = 1e9;
    FOR(i, 1, C+1) FOR(j, 1, C+1) FOR(k, 1, C+1){
        if (i == j || j == k || i == k) continue;
        // case (i+j)%3
        int d = 0;
        FOR(from, 1, C+1){
            d += m[0][from] * D[from][i];
            d += m[1][from] * D[from][j];
            d += m[2][from] * D[from][k];
        }
        // cout << d << endl;
        mind = min(mind, d);
    }
    cout << mind << endl;
}
