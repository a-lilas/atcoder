#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> mat;

int main(){
    int a, b;
    cin >> a >> b;
    int d = b - a;
    int c = 0;
    FOR(i, 1, d) c += i;
    cout << (c - a) << endl;
}