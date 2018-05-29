#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ios>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <sstream>
#include <bitset>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

int main(){
    // 動的計画法で長方形の右下までの面積を全て求める
    int N; cin >> N;
    int D[N][N];
    REP(i, N)REP(j, N) cin >> D[i][j];
    int Q; cin >> Q;
    int P[Q];
    REP(i, Q) cin >> P[i];

    // dp[i][j]: 左上の座標(i, j)から，右下までの長方形の面積
    int dp[1000][1000] = {};
    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>=0; j--){
            dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1] + D[i][j];
        }
    }

    int d_arr[N*N+1];
    REP(i, N*N+1) d_arr[i] = 0;

    // たこ焼きの数の全パターンについて，先に美味しさの合計を求めておく．
    FOR(h, 1, N+1) FOR(w, 1, N+1){
        FOR(lx, 0, N+1-h) FOR(ly, 0, N+1-w){
            d_arr[h*w] = max({d_arr[h*w],
                              dp[lx][ly]-dp[lx+h][ly]-dp[lx][ly+w]+dp[lx+h][ly+w]});
        }
    }

    FOR(i, 1, N*N+1) d_arr[i] = max(d_arr[i], d_arr[i-1]);

    REP(i, Q) cout << d_arr[P[i]] << endl;
}
