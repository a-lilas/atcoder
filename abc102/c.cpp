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
    int n; cin >> n;
    vi a(n);
    REP(i, n) cin >> a[i];
    vector<ll> s;
    ll sum = 0;
    REP(i, n){
        // sum += a[i] - (i+1);
        s.pb(a[i]-(i+1));
    }
    sort(ALL(s));
    if (n % 2 == 0){
        vector<ll> ans;
        ll sum = 0;
        REP(k, 2){
            REP(i, n){
                sum += abs(a[i]-s[(n/2)+k]-(i+1));
            }
            ans.pb(sum);
        }
        cout << min(ans[0], ans[1]) << endl;
    }else{
        ll sum = 0;
        REP(i, n){
            sum += abs(a[i]-s[(n/2)]-(i+1));
        }
        cout << sum << endl;
    }
}