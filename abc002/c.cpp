// ABC002 C-直訴

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ios>
#include <iomanip>
#include <limits>
#include <algorithm>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<e; i++)

using namespace std;

int main(){
    int xa, ya, xb, yb, xc, yc;
    double S;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    xb -= xa;
    xc -= xa;
    yb -= ya;
    yc -= ya;

    S = abs(xb*yc - yb*xc) / 2.0;
    cout << fixed << setprecision(5) << S << endl;
}
