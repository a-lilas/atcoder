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

int main(){
    int N;
    int in;
    vector<int> A;
    cin >> N;
    REP(i, N){
        cin >> in;
        A.push_back(in);
    }

    long long ans = 0;
    long long cumsum = 0, cumxor = 0, r = 0;
    REP(l, N){
        while ((cumsum+A[r]) == (cumxor^A[r]) && r < N){
            cumsum += A[r];
            cumxor ^= A[r];
            r++;
        }
        ans += r - l;
        cumsum -= A[l];
        cumxor ^= A[l];
    }

    cout << ans << endl;
}