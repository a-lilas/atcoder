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
    int d[k];
    REP(i, k) cin >> d[i];
    int i = 0;
    while(true){
        bool ng = false;
        int p = n + i;
        while(p > 0){
            REP(j, k){
                if (p % 10 == d[j]) ng = true;
            }
            if (ng) break;
            p /= 10;
        }
        if (!ng) break;
        i++;
    }
    cout << (n+i) << endl;
}