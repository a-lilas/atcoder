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
    int minans = 1e9;
    cin >> N;
    REP(i, N){
        int in;
        cin >> in;
        minans = min(minans, in);
    }
    cout << minans << endl;
}