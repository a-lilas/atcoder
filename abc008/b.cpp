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

int main(){
    int N; cin >> N;
    string s;
    map<string, int> m;
    REP(i, N){
        cin >> s;
        m[s]++;
    }
    int maxans = 0;
    string ans;
    for(auto it=m.begin(); it!=m.end(); it++){
        if (maxans < it->second){
            maxans = it->second;
            ans = it->first;
        }
    }
    cout << ans << endl;
}
