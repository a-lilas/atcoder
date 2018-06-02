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
    int N, M; cin >> N >> M;
    int b, c;
    bool ok = false;
    REP(i, M-2*N+1){
        b = i;
        if ((M-2*N-b) % 2 == 0){
            c = (M-2*N-b) / 2;
            if (b + c > N) continue;
            ok = true;
            break;
        }
    }
    if (ok) cout << N - b - c << " " << b << " " << c << endl;
    else cout << "-1 -1 -1" << endl;
}