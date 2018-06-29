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
    int n, l; cin >> n >> l;
    string s[n];
    REP(i, n) cin >> s[i];
    sort(s, s+n);
    REP(i, n) cout << s[i];
    cout << endl;
}