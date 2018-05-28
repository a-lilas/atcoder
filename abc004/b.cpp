// ABC004 B-回転

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
    char c[4][4];
    char ans[4][4];
    REP(i, 4) cin >> c[i][0] >> c[i][1] >> c[i][2] >> c[i][3];

    FOR(i, 1, 5) FOR(j, 1, 5){
        ans[i-1][j-1] = c[4-i][4-j];
    }
    REP(i, 4){
        cout << ans[i][0] << " ";
        cout << ans[i][1] << " ";
        cout << ans[i][2] << " ";
        cout << ans[i][3] << endl;
    }
}