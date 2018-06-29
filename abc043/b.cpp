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

int main(){
    string s; cin >> s;
    string ans = "";
    REP(i, s.size()){
        if (s[i] == '0') ans += "0";
        else if (s[i] == '1') ans += "1";
        else if (ans.size() > 0 && s[i] == 'B') ans.pop_back();
        else continue;
    }
    cout << ans << endl;
}