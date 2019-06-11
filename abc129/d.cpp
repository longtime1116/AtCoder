#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli table_w[2001][2001];
lli table_h[2001][2001];

int main() {
    lli h, w;
    cin >> h >> w;
    string str[h];
    REP(i, 0, h) {
        string x;
        cin >> x;
        str[i] = x;
    }

    REP(i, 0, h) {
        lli s = 0;
        lli e = 0;
        REP(j, 0, w) {
            if (str[i][j] == '#') {
                for(lli k = s; k < e; k++) {
                    table_w[i][k] = e-s;
                }
                s = j+1;
                e = j+1;
            }
            else if (j == w-1) {
                e++;
                for(lli k = s; k < e; k++) {
                    table_w[i][k] = e-s;
                }
            }
            else {
                e++;
            }
        }
    }
    //REP(i, 0, h) {
    //    REP(j, 0, w) {
    //        cout << table_w[i][j] << ", ";
    //    }
    //        cout << endl;
    //}

    REP(i, 0, w) {
        lli s = 0;
        lli e = 0;
        REP(j, 0, h) {
            if (str[j][i] == '#') {
                for(lli k = s; k < e; k++) {
                    table_h[k][i] = e-s;
                }
                s = j+1;
                e = j+1;
            }
            else if (j == h-1) {
                e++;
                for(lli k = s; k < e; k++) {
                    table_h[k][i] = e-s;
                }
            }
            else {
                e++;
            }
        }
    }
    //cout << endl;
    //REP(i, 0, h) {
    //    REP(j, 0, w) {
    //        cout << table_h[i][j] << ", ";
    //    }
    //        cout << endl;
    //}
    lli ans = 0;
    REP(i, 0, h) {
        REP(j, 0, w) {
            lli total;
            total = table_h[i][j] + table_w[i][j] - 1;
            ans = max(ans, total);
        }
    }
    cout << ans << endl;
}
