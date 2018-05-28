// ABC004 C-入れ替え

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
    int N;
    queue<int> q;
    cin >> N;
    FOR(i, 1, 7) q.push(i);
    int f;
    REP(i, (int)(N/5) % 6){
        f = q.front();
        q.pop();
        q.push(f);
    }
    f = q.front();
    q.pop();
    REP(i, 6){
        if (i == N % 5) cout << f;
        else{
            cout << q.front();
            q.pop();
        }
    }
    cout << endl;
}