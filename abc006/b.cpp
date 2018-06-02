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
#define MOD 10007

using namespace std;

int main(){
    int n; cin >> n;
    long long int tri[n];
    tri[0] = 0; tri[1] = 0; tri[2] = 1;
    FOR(i, 3, n){
        tri[i] = (tri[i-1] + tri[i-2] + tri[i-3]) % MOD;
    }
    cout << tri[n-1] << endl;
}