// ABC001 C-風力観測

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ios>
#include <iomanip>
#define REP(i, n) for(int i=0; i<n; ++i)

using namespace std;

int main(){
    int d1, d2;
    double deg, dis;
    vector<double> dis_v{0.0, 0.3, 1.6, 3.4, 5.5, 8.0,
                         10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7};
    map<double, string> deg_m;
    deg_m[0.0] = "N";
    deg_m[11.25] = "NNE";
    deg_m[33.75] = "NE";
    deg_m[56.25] = "ENE";
    deg_m[78.75] = "E";
    deg_m[101.25] = "ESE";
    deg_m[123.75] = "SE";
    deg_m[146.25] = "SSE";
    deg_m[168.75] = "S";
    deg_m[191.25] = "SSW";
    deg_m[213.75] = "SW";
    deg_m[236.25] = "WSW";
    deg_m[258.75] = "W";
    deg_m[281.25] = "WNW";
    deg_m[303.75] = "NW";
    deg_m[326.25] = "NNW";

    cin >> d1 >> d2;
    deg = d1 / 10.0;
    dis = d2 / 60.0;

    dis = int(dis * 10 + 0.5);
    dis /= 10;

    string dir;
    int w;

    REP(i, 13){
        if (dis < dis_v[i]){
            w = i - 1;
            break;
        }
        w = 12;
    }
    if (w == 0) dir = "C";
    else{
        string prev_dir;
        for (auto it=deg_m.begin(); it!=deg_m.end(); it++){
            if (deg < it->first){
                dir = prev_dir;
                break;
            }
            prev_dir = it->second;
            dir = deg_m[326.25];
            if (deg >= 348.75) dir = "N";
        }
    }

    cout << dir << ' ' << w << endl;
}