// ABC003 B-AtCoder社のトランプ

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
    string S, T;
    string wild = "atcoder";
    cin >> S >> T;

    bool ok;
    REP(i, S.size()){
        ok = false;
        if (S[i] == T[i]){
            ok = true;
            continue;
        }
        if (S[i] == '@'){
            REP(j, wild.size()){
                if (T[i] == wild[j]){
                    ok = true;
                }
            }
        }
        if (T[i] == '@'){
            REP(j, wild.size()){
                if (S[i] == wild[j]){
                    ok = true;
                }
            }
        }
        if(!ok) break;
    }
    if (ok){
        cout << "You can win" << endl;
    }else{
        cout << "You will lose" << endl;
    }
}