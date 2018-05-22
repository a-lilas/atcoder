// ABC001 D-感雨時刻の整理

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ios>
#include <iomanip>
#include <algorithm>
#define REP(i, n) for(int i=0; i<n; ++i)

using namespace std;

int main(){
    int N;
    vector<int> S, E;
    vector<int> S_ans, E_ans;
    queue<int> Sq, Eq;
    string input;
    cin >> N;

    REP(i, N){
        cin >> input;
        S.push_back(stoi(input.substr(0, 4)));
        E.push_back(stoi(input.substr(5, 9)));
        S[i] -= (S[i] % 5);
        if (E[i] % 5 != 0) E[i] += (5 - (E[i] % 5));
        if (S[i] % 100 == 60) S[i] += 40;
        if (E[i] % 100 == 60) E[i] += 40;
    }

    sort(S.begin(), S.end());
    sort(E.begin(), E.end());

    REP(i, N){
        Sq.push(S[i]);
        Eq.push(E[i]);
    }

    int cnt = 0;

    while(!Eq.empty()){
        if (Sq.empty()){
            while (cnt > 1){
                Eq.pop();
                cnt--;
            }
            E_ans.push_back(Eq.front());
            Eq.pop();
            cnt--;
            continue;
        }

        if (Sq.front() == Eq.front()){
            Eq.pop();
            Sq.pop();
        }else if (Sq.front() < Eq.front()){
            if (cnt == 0){
                S_ans.push_back(Sq.front());
                Sq.pop();
                cnt++;
            }
            while (!Sq.empty() && Sq.front() < Eq.front()){
                Sq.pop();
                cnt++;
            }
        }else{
            while (cnt > 1){
                Eq.pop();
                cnt--;
            }
            E_ans.push_back(Eq.front());
            Eq.pop();
            cnt--;
        }
    }
    REP(i, S_ans.size()){
        cout << setfill('0') << right << setw(4) << S_ans[i];
        cout << "-";
        cout << setfill('0') << right << setw(4) << E_ans[i] << endl;
    }
}