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

long long count(string num){
    // dp[i桁目まで見た][1:数がギリギリ][1:4もしくは9が含まれている]
    // -> 上からi桁目まで見たときの条件を満たす数の総数
    long long dp[20][2][2] = {0};
    dp[0][0][0] = 1;
    REP(i, num.size()) REP(j, 2) REP(k, 2){
        int lim = j ? 9 : num[i] - '0';
        REP(d, lim+1){
            dp[i+1][j || d < lim][k || (d == 4 || d == 9)] += dp[i][j][k];
        }
    }
    return dp[num.size()][1][1] + dp[num.size()][0][1];
}

int main(){
    long long A, B; cin >> A >> B;
    A = A - 1;
    string a = to_string(A);
    string b = to_string(B);
    cout << (count(b) - count(a)) << endl;
}