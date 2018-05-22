// ABC001 B-視程の通報

#include <iostream>
#include <ios>
#include <iomanip>

using namespace std;

int main(){
    double m;
    int vv;
    cin >> m;
    m /= 1000.0;
    if (m < 0.1) vv = 0;
    if (0.1 <= m && m <= 5) vv = m*10;
    if (6 <= m && m <= 30) vv = m + 50;
    if (35 <= m && m <= 70) vv = (m - 30) / 5 + 80;
    if (70 < m) vv = 89;

    cout << setfill('0') << right << setw(2) << vv << endl;
}
