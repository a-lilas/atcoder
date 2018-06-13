#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

int dp[200000];

int main(){
    int N; cin >> N;
    vi m;
    m.push_back(1);
    FOR(i, 1, 8) m.push_back(pow(6, i));
    FOR(i, 1, 8) m.push_back(pow(9, i));
    sort(m.begin(), m.end());

    REP(i, N+1) dp[i] = 1e9;
    dp[0] = 0;

    FOR(i, 1, N+1){
        int minres = 1e9;
        for(int j=m.size()-1; j>=0; j--){
            int n = m[j];
            if (i-n >= 0){
                minres = min(minres, dp[i-n]);
            }
        }
        dp[i] = minres+1;
    }

    cout << dp[N] << endl;
}