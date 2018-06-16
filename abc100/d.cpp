#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

int main(){
    int N, M; cin >> N >> M;
    ll x[N], y[N], z[N];
    vector<ll> sum(N);
    int pm_x[8] = {-1, -1, -1, -1, 1, 1, 1, 1};
    int pm_y[8] = {-1, -1, 1, 1, -1, -1, 1, 1};
    int pm_z[8] = {-1, 1, -1, 1, -1, 1, -1, 1};
    REP(i, N){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll maxans = -1;
    REP(i, 8){
        REP(j, N){
            sum[j] = pm_x[i]*x[j] + pm_y[i]*y[j] + pm_z[i]*z[j];
        }
        sort(sum.begin(), sum.end());
        ll ans = 0;
        REP(j, M){
            ans += sum[sum.size()-1-j];
            // ans += sum[j];
        }
        maxans = max(maxans, ans);
    }
    cout << maxans << endl;
}