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
    string input;
    cin >> N;

    REP(i, N){
        cin >> input;
        S.push_back(60*stoi(input.substr(0, 2)) + stoi(input.substr(2, 2)));
        E.push_back(60*stoi(input.substr(5, 2)) + stoi(input.substr(7, 2)));
        S[i] -= (S[i] % 5);
        if (E[i] % 5 != 0) E[i] += (5 - (E[i] % 5));
    }

    int im[60*24+1] = {0};

    REP(i, N){
        im[S[i]] += 1;
        im[E[i]] += -1;
    }

    if (im[0] > 0) S_ans.push_back(0);
    for(int i=1; i<=60*24; ++i){
        im[i] += im[i-1];
        if(im[i] > 0 && im[i-1] == 0) S_ans.push_back(i);
        if(im[i] == 0 && im[i-1] > 0) E_ans.push_back(i);
    }
    if(im[60*24] > 0) E_ans.push_back(60*24);

    REP(i, S_ans.size()){
        cout << setfill('0') << right << setw(2) << (S_ans[i] / 60);
        cout << setfill('0') << right << setw(2) << (S_ans[i] % 60);
        cout << "-";
        cout << setfill('0') << right << setw(2) << (E_ans[i] / 60);
        cout << setfill('0') << right << setw(2) << (E_ans[i] % 60);
        cout << endl;
    }
}