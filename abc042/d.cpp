#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define ALL(n) (n).begin(), (n).end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

const ll MAX = 250000;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll fact[MAX+1], fact_inv[MAX+1];

ll pow_mod(ll n, ll r, ll p){
    // n^r mod p   O(logn)
    if (r == 0) return 1;
    if (r % 2 == 0) return pow_mod(n*n%p , r/2, p) % p;
    else return n * pow_mod(n, r-1, p) % p;
}

void factorial(ll n, ll p){
    fact[0] = 1;
    fact[1] = 1;
    FOR(i, 2, n+1) fact[i] = i * fact[i-1] % p;
    fact_inv[n] = pow_mod(fact[n], p-2, p);
    for(int i=n-1; i>=0; --i) fact_inv[i] = fact_inv[i+1] * (i+1) % p;
}

ll comb(ll n, ll r, ll p){
    // nCr mod p
    if (n < 0 || r < 0 || r > n) return 0;
    return (fact[n] * fact_inv[r] % p) * fact_inv[n-r] % p;
}


int main(){
    int h, w, a, b; cin >> h >> w >> a >> b;
    factorial(MAX, MOD);
    ll ans = 0;
    REP(i, h-a){
        ans += comb((b-1+i), i, MOD) * comb(h-1-i+(w-b-1), w-b-1, MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
