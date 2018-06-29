#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define ALL(n) (n).begin(), (n).end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

const ll MAX_V = 100000;
const ll INF = 1e9;
const ll MOD = 998244353;

// AA, AXA の形が存在するかどうかチェックすればよい

int main(){
    string s; cin >> s;
    bool ok = false;
    int l, r;
    REP(i, s.size()-2){
        if (s[i] == s[i+1]){
            l = i + 1;
            r = i + 2;
            ok = true;
            break;
        }
        if (s[i] == s[i+2]){
            l = i + 1;
            r = i + 3;
            ok = true;
            break;
        }
    }
    if (s[s.size()-2] == s[s.size()-1]){
        ok = true;
        l = s.size() - 1;
        r = s.size();
    }
    if (ok) cout << l << " " << r << endl;
    else cout << "-1 -1" << endl;
}