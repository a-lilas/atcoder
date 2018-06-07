#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ios>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <sstream>
#include <bitset>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
    int N; cin >> N;
    int c[N];
    REP(i, N) cin >> c[i];
    double ans = 0.0;

    REP(i, N){
        int num = 0;
        REP(j, N){
            if (c[i] % c[j] == 0) num++;
        }
        // c[i] = c[j]の場合を引く
        num--;

        if (num % 2 == 0){
            ans += (num + 2.0) / (2.0 * num + 2.0);
        }else{
            ans += 0.5;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}
