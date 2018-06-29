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
    int a, b, c; cin >> a >> b >> c;
    if (a == 5 && b == 5 && c == 7) cout << "YES" << endl;
    else if (a == 5 && b == 7 && c == 5) cout << "YES" << endl;
    else if (a == 7 && b == 5 && c == 5) cout << "YES" << endl;
    else cout << "NO" << endl;
}