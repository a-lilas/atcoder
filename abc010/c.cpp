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
    int sx, sy, gx, gy, T, V;
    cin >> sx >> sy >> gx >> gy >> T >> V;
    int n; cin >> n;
    vi x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    bool ok = false;
    REP(i, n){
        double d;
        d = sqrt(pow(sx-x[i], 2) + pow(sy-y[i], 2)) +
            sqrt(pow(x[i]-gx, 2) + pow(y[i]-gy, 2));
        if (d <= T*V){
            ok = true;
            break;
        }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}