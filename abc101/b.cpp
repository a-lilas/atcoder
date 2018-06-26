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
    int n, nn; cin >> n;
    int s = 0;
    nn = n;
    while(n > 0){
        s += (n % 10);
        n /= 10;
    }
    if (nn % s == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}