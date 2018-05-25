// ABC003 C-AtCoderプログラミング講座
// memo: レートが高い順にK個見る動画を選択し，K個の中から小さい順に選択していく．

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
    int N, K, input;
    double ans = 0.0;
    vector<int> R;
    cin >> N >> K;

    REP(i, N){
        cin >> input;
        R.push_back(input);
    }

    sort(R.begin(), R.end(), greater<int>());

    for(int i=K-1; i>=0; i--){
        ans = (ans + R[i]) / 2.0;
    }
    cout << fixed << setprecision(12) << ans << endl;
}