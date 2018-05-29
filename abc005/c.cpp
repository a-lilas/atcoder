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
    int T, N, M;
    cin >> T >> N;
    int A[N];
    REP(i, N) cin >> A[i];
    cin >> M;
    int B[M];
    REP(i, M) cin >> B[i];

    int idx = 0;
    bool ok;
    REP(i, M){
        ok = false;
        if (N < M || idx >= N){
            break;
        }
        while(idx < N){
            if (B[i] - A[idx] >= 0 && B[i] - A[idx] <= T){
                ok = true;
                idx++;
                break;
            }
            idx++;
        }
    }
    if (ok) cout << "yes" << endl;
    else cout << "no" << endl;
}