#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

int main(){
    int N; cin >> N;
    int a[N];
    int cnt = 0;
    REP(i, N){
        cin >> a[i];
        while(a[i] % 2 == 0){
            a[i] /= 2;
            cnt++;
        }
    }
    cout << cnt << endl;
}