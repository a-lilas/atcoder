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
    int N; cin >> N;
    int c[N]; REP(i, N) cin >> c[i];

    int dp[N];
    REP(i, N) dp[i] = 1e9;

    REP(i, N){
        *lower_bound(dp, dp+N, c[i]) = c[i];
    }

    cout << N - (lower_bound(dp, dp+N, 1e9) - dp) << endl;
}
