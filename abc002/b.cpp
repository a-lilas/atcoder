// ABC002 B-罠

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ios>
#include <iomanip>
#include <algorithm>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<e; i++)

using namespace std;

int main(){
    string W, ans;
    cin >> W;
    ans = "";
    REP(i, W.size()){
        if (W[i] == 'a' || W[i] == 'i' || W[i] == 'u' || W[i] == 'e' || W[i] == 'o'){
            continue;
        }
        ans += W[i];
    }

    cout << ans << endl;
}