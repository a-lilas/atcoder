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
const int MAX_N = 2 * 1e5;

int main(){
    int n; cin >> n;
    vi a(n);
    vector<ll> cumsum;
    REP(i, n){
        cin >> a[i];
        if (i == 0) cumsum.pb(a[i]);
        else cumsum.pb(cumsum[i-1] + a[i]);
    }

    ll minans = 1e15, ans;
    FOR(i, 1, n-2){
        FOR(j, -1, 2) FOR(k, -1, 2){
            ll p = *(upper_bound(cumsum.begin(), cumsum.begin()+i, cumsum[i]/2) - j);
            ll q = cumsum[i] - p;
            ll r = *(upper_bound(cumsum.begin()+i+1, cumsum.end(), (cumsum[n-1]+cumsum[i])/2) - k) - cumsum[i];
            ll s = cumsum[n-1] - cumsum[i] - r;
            if (p == 0 || q == 0 || r == 0 || s == 0) continue;
            ans = abs(max({p, q, r, s}) - min({p, q, r, s}));
            minans = min(minans, ans);
        }
    }

    cout << minans << endl;

}