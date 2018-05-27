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
    int W[N] = {};
    int E[N] = {};

    if (S[0] == 'W') W[0] = 1;
    else E[0] = 1;

    FOR(i, 1, N){
        if (S[i] == 'W'){
            W[i] = W[i-1] + 1;
            E[i] = E[i-1];
        }
        else{
            W[i] = W[i-1];
            E[i] = E[i-1] + 1;
        }
    }

    int minans = E[N-1];

    REP(i, N){
        minans = min(minans, W[i] + E[N-1] - E[i]);
    }

    cout << minans << endl;
}
