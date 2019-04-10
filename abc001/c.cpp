#include <bits/stdc++.h>
using namespace std;

int main() {
    int deg, dis;
    string dir;
    int w;

    cin >> deg >> dis;

    if (deg < 113)
        dir = "N";
    else if (deg < 338)
        dir = "NNE";
    else if (deg < 563)
        dir = "NE";
    else if (deg < 788)
        dir = "ENE";
    else if (deg < 1013)
        dir = "E";
    else if (deg < 1238)
        dir = "ESE";
    else if (deg < 1463)
        dir = "SE";
    else if (deg < 1688)
        dir = "SSE";
    else if (deg < 1913)
        dir = "S";
    else if (deg < 2138)
        dir = "SSW";
    else if (deg < 2363)
        dir = "SW";
    else if (deg < 2588)
        dir = "WSW";
    else if (deg < 2813)
        dir = "W";
    else if (deg < 3038)
        dir = "WNW";
    else if (deg < 3263)
        dir = "NW";
    else if (deg < 3488)
        dir = "NNW";
    else
        dir = "N";

    double diss = round((dis/60.0 * 10))/10.0;
    if (diss < 0.3)
        w = 0;
    else if (diss < 1.6)
        w = 1;
    else if (diss < 3.4)
        w = 2;
    else if (diss < 5.5)
        w = 3;
    else if (diss < 8.0)
        w = 4;
    else if (diss < 10.8) // 642
        w = 5;
    else if (diss < 13.9) // 828
        w = 6;
    else if (diss < 17.2)
        w = 7;
    else if (diss < 20.8)
        w = 8;
    else if (diss < 24.5)
        w = 9;
    else if (diss < 28.5)
        w = 10;
    else if (diss < 32.7)
        w = 11;
    else
        w = 12;

    if (w == 0)
        dir = "C";

    cout << dir << " " << w << endl;
}
