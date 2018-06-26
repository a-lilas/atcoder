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
    int k; cin >> k;
    vector<ll> su;
    vector<ll> ans;
    FOR(i, 1, 10) su.pb(i);
    FOR(i, 1, 10000){
        FOR(j, 1, 14){
            ll nine = pow(10, j) - 1;
            su.pb(i*pow(10, j) + nine);
        }
    }
    sort(ALL(su));
    for(int i=su.size()-2; i>=0; i--){
        if (su[i] == su[i+1]) su.erase(su.begin()+i+1);
    }

    double mindiv;

    for(int i=su.size()-1; i>=0; i--){
        int s = 0;
        ll tmp = su[i];
        while(tmp > 0){
            s += tmp % 10;
            tmp /= 10;
        }
        if (i == su.size()-1) mindiv = su[i] / double(s);
        else if (su[i] / double(s) <= mindiv){
            ans.pb(su[i]);
        }
        mindiv = min(mindiv, su[i]/double(s));
    }
    sort(ALL(ans));
    REP(i, k) cout << ans[i] << endl;
}