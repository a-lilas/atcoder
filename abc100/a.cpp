#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, n) for(int i=s; i<n; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

int main(){
    int A, B; cin >> A >> B;
    if (A <= 8 && B <= 8){
        cout << "Yay!" << endl;
    }else{
        cout << ":(" << endl;
    }
}