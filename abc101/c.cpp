#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define ALL(n) (n).begin(), (n).end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

const ll MAX_V = 100000;
const ll INF = 1e9;
const ll MOD = 998244353;

int main(){
    int n, k; cin >> n >> k;
    vi a(n);
    REP(i, n) cin >> a[i];
    int ans = (n-1) / (k-1);
    int m = (n-1) % (k-1);

    if (m == 0) cout << ans << endl;
    else cout << (ans + 1) << endl;
}