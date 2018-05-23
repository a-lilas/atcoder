// ABC002 D-派閥

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
    int N, M;
    vector<int> x, y;
    int ans = 0;
    cin >> N >> M;
    REP(i, M){
        int tx, ty;
        cin >> tx >> ty;
        x.push_back(tx);
        y.push_back(ty);
    }
    REP(i, pow(2, N)){
        string s;
        bool fg = false;
        vector<int> friends;
        s = bitset<12>(i).to_string();
        reverse(s.begin(), s.end());
        REP(j, N){
            if (s[j] == '1') friends.push_back(j);
        }
        REP(j, friends.size()){
            FOR(k, j+1, friends.size()){
                fg = false;
                REP(l, x.size()){
                    if (friends[j] == x[l]-1 && friends[k] == y[l]-1){
                        fg = true;
                        break;
                    }
                }
                if (!fg) break;
            }
            if (!fg) break;
        }
        if (fg){
            ans = max(ans, int(friends.size()));
        }
    }
    if (ans == 0) ans = 1;
    cout << ans << endl;
}