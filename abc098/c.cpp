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
    string S;
    cin >> N;
    cin >> S;
    int W = 0;
    int E = 0;
    int ans = 0;
    int minans = 0;

    REP(i, N){
        if (S[i] == 'W') W++;
        else E++;
    }
    if (S[0] == 'W') ans = E;
    else ans = E - 1;
    minans = ans;

    char pre;
    pre = S[0];
    FOR(i, 1, N){
        if (pre == 'W' && S[i] == 'W'){
            ans++;
        }else if (pre == 'E' && S[i] == 'E'){
            ans--;
        }
        minans = min(ans, minans);
        pre = S[i];
    }

    cout << minans << endl;
}
