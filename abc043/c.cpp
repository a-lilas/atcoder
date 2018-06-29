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
    int a[n];
    REP(i, n) cin >> a[i];
    int sum = 0;
    REP(i, n) sum += a[i];
    int mean = sum / n;

    int cost_a = 0, cost_b = 0;
    REP(i, n){
        cost_a += pow((mean - a[i]), 2);
    }
    REP(i, n){
        cost_b += pow((mean+1 - a[i]), 2);
    }
    cout << min(cost_a, cost_b) << endl;
}
