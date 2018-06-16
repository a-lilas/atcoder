#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

int main(){
    int D, N;
    cin >> D >> N;
    int ans;
    if (N == 100){
        ans = pow(100, D) * (N+1);
    }else{
        ans = pow(100, D) * N;
    }
    cout << ans << endl;
}