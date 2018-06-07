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
    int dx[] = {1, -1, 0,  0};
    int dy[] = {0,  0, 1, -1};

    int R, C; cin >> R >> C;
    int sy, sx; cin >> sy >> sx;
    int gy, gx; cin >> gy >> gx;
    char c[R][C];
    int num[R][C];
    REP(i, R) REP(j, C){
        cin >> c[i][j];
    }
    queue<vector<int>> q;
    q.push({sy-1, sx-1, 0});
    c[sy-1][sx-1] = '#';
    vector<int> now;
    while(!q.empty()){
        now = q.front();
        q.pop();
        if (now[0] == gy-1 && now[1] == gx-1) break;
        REP(i, 4){
            if (c[now[0]+dy[i]][now[1]+dx[i]] == '.'){
                q.push({now[0]+dy[i], now[1]+dx[i], now[2]+1});
                c[now[0]+dy[i]][now[1]+dx[i]] = '#';
            }
        }
    }
    cout << now[2] << endl;
}