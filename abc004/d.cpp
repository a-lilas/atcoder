// ABC004 D-マーブル

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
    int R, G, B;
    int R_pos = 400;
    int G_pos = 500;
    int B_pos = 600;
    cin >> R >> G >> B;
    int N = R + G + B;
    int dp[1000][1000] = {};
    REP(i, 1000) REP(j, 1000) dp[i][j] = 1e9;
    REP(i, 1000) dp[i][N] = 0;
    FOR(i, 1, 1000){
        REP(j, N){
            if (j >= N-R){
                // マーブル=R
                // dp[i][j]は「今i番目の箱に注目しており，残りのマーブル数がj個のときの，最小移動回数」
                // min(iに置かないパターン(jは据え置き), iに置くパターン(j+1個から1個使う))
                dp[i][j] = min({dp[i-1][j], dp[i-1][j+1] + abs(R_pos - i)});
            }else if (j >= N-R-G){
                // マーブル=G
                dp[i][j] = min(dp[i-1][j], dp[i-1][j+1] + abs(G_pos - i));
            }else{
                // マーブル=B
                dp[i][j] = min(dp[i-1][j], dp[i-1][j+1] + abs(B_pos - i));
            }
        }
    }
    int ans = 1e9;
    REP(i, 1000){
        ans = min(ans, dp[i][0]);
    }
    cout << ans << endl;
}