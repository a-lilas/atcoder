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
  string s; cin >> s;
  if (s == "a") cout << -1 << endl;
  else if (s.size() == 1) cout << "a" << endl;
  else cout << s.substr(0, s.size()-1) << endl;
}
