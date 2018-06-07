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

typedef long long ll;
typedef vector<int> vi;
// (x, y, w, h) 範囲は[x, x+w), [y, y+h)
typedef tuple<int, int, int, int> tp;

int W, H;
int N;
int X[100], Y[100];
map<tp, int> dp;

int memo(tp t){
    // 領域の左上の座標・幅・高さから，
    // 装置を動かしたときに得られる金塊の最大値を返す
    int res = 0;
    int maxres = 0;
    int lx, ly, w, h;
    tie(lx, ly, w, h) = t;

    if (dp[t] != 0) return dp[t];

    REP(i, N){
        if (lx <= X[i] && X[i] < (lx+w)){
            if (ly <= Y[i] && Y[i] < (ly+h)){
                res = w + h - 1;
                tp r1 = make_tuple(lx, ly, (X[i]-lx), (Y[i]-ly));
                tp r2 = make_tuple(X[i]+1, ly, (lx+w-1-X[i]), (Y[i]-ly));
                tp r3 = make_tuple(lx, Y[i]+1, (X[i]-lx), (ly+h-1-Y[i]));
                tp r4 = make_tuple(X[i]+1, Y[i]+1, (lx+w-1-X[i]), (ly+h-1-Y[i]));
                res += memo(r1) + memo(r2) + memo(r3) + memo(r4);
                maxres = max(maxres, res);
            }
        }
    }

    dp[t] = maxres;
    return maxres;
}

int main(){
    cin >> W >> H;
    cin >> N;
    REP(i, N){
        int x, y;
        cin >> x >> y;
        X[i] = x - 1;
        Y[i] = y - 1;
    }
    tp init = make_tuple(0, 0, W, H);
    cout << memo(init) << endl;
}