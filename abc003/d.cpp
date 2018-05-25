// ABC003 D-AtCoder社の冬

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
#define MOD 1000000007

using namespace std;

long long pow_mod(int n, int r, long long p){
    // n^r mod p (O(logn))
    if (r == 0) return 1;
    if (r % 2 == 0) return pow_mod(((n%p)*(n%p))%p , r/2, p) % p;
    else return ((n%p) * (pow_mod(n, r-1, p)%p)) % p;
}

long long nCr_mod(int n, int r, long long p){
    // nCr mod p
    // n! / r!(n-r)!
    // global variable (factorial vector) vector<long long> f_mod_vec;
    if (n < 0 || r < 0 || n < r) return 0;
    vector<long long> f_mod_vec;
    long long factorial = 1;
    f_mod_vec.push_back(1);
    for(int i=1; i<=n; i++){
        factorial = ((factorial % p) * (i % p)) % p;
        f_mod_vec.push_back(factorial);
    }
    long long d = (f_mod_vec[r] * f_mod_vec[n-r]) % p;
    return (f_mod_vec[n] * (pow_mod(d, p-2, p))) % p;
}


int main(){
    int R, C, X, Y, D, L;
    long long ans = 0;
    cin >> R >> C >> X >> Y >> D >> L;

    if (X*Y != D+L){
        // all case
        long long all = (nCr_mod(X*Y, D, MOD) * nCr_mod(X*Y-D, L, MOD)) % MOD;

        long long ng = 2 * nCr_mod((X-1)*Y, D, MOD) * nCr_mod((X-1)*Y-D, L, MOD) % MOD
                     + 2 * nCr_mod(X*(Y-1), D, MOD) * nCr_mod(X*(Y-1)-D, L, MOD) % MOD
                     - 4 * nCr_mod((X-1)*(Y-1), D, MOD) * nCr_mod((X-1)*(Y-1)-D, L, MOD) % MOD
                     - nCr_mod((X-2)*Y, D, MOD) * nCr_mod((X-2)*Y-D, L, MOD) % MOD
                     - nCr_mod(X*(Y-2), D, MOD) * nCr_mod(X*(Y-2)-D, L, MOD) % MOD
                     + 2 * nCr_mod((X-1)*(Y-2), D, MOD) * nCr_mod((X-1)*(Y-2)-D, L, MOD) % MOD
                     + 2 * nCr_mod((X-2)*(Y-1), D, MOD) * nCr_mod((X-2)*(Y-1)-D, L, MOD) % MOD
                     - nCr_mod((X-2)*(Y-2), D, MOD) * nCr_mod((X-2)*(Y-2)-D, L, MOD) % MOD;
        if (ng < 0) ng += MOD;
        ans = all - ng;
    }else{
        ans = (nCr_mod(X*Y, D, MOD) * nCr_mod(X*Y-D, L, MOD)) % MOD;
    }
    if (ans < 0) ans += MOD;
    ans = (ans * ((R-X+1) % MOD) % MOD) * ((C-Y+1) % MOD) % MOD;
    cout << ans << endl;
}
