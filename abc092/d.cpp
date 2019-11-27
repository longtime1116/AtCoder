#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

// input
#define cin1(x)             cin >> x
#define cin2(x, y)          cin >> x >> y
#define cin3(x, y, z)       cin >> x >> y >> z
#define ncin1(n, x)         REP(i, 0, n) { cin1(x[i]); }
#define ncin2(n, x, y)      REP(i, 0, n) { cin2(x[i], y[i]); }
#define ncin3(n, x, y, z)   REP(i, 0, n) { cin3(x[i], y[i], z[i]); }
#define ncinp(n, p)         REP(i, 0, n) { lli p1,p2; cin >> p1 >> p2; p[i] = P(p1, p2); }
#define ncin1_1(n, x)       REPE(i, 1, n) { cin1(x[i]); }
#define ncin2_1(n, x, y)    REPE(i, 1, n) { cin2(x[i], y[i]); }
#define ncin3_1(n, x, y, z) REPE(i, 1, n) { cin3(x[i], y[i], z[i]); }
#define ncinp_1(n, p)       REPE(i, 1, n) { lli p1,p2; cin >> p1 >> p2; p[i] = P(p1, p2); }

// output
#define cout1(x)         cout << #x << ": " << x << endl;
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;
typedef vector<lli> vlli;

int main() {
    lli a,b;
    cin2(a,b);

    // true => 白(aの方)
    bool up[50][100];
    bool down[50][100];
    REP(i,0,50) {
        REP(j,0,100) {
            up[i][j] = false;
            down[i][j] = true;
        }
    }

    lli row = 0;
    lli col = 0;
    REP(i,0,a-1) {
        up[row][col] = true;
        col += 2;
        if (col >= 100) {
            row += 2;
            col = 0;
        }
    }
    row = 0;
    col = 0;
    REP(i,0,b-1) {
        down[row][col] = false;
        col += 2;
        if (col >= 100) {
            row += 2;
            col = 0;
        }
    }

    cout << "100 100" << endl;
    REP(i,0,50) {
        REP(j,0,100) {
            if (up[i][j]) {
                cout << '.';
            }
            else {
                cout << '#';
            }
        }
        cout << endl;
    }
    REPE_R(i,49,0) {
        REPE_R(j,99,0) {
            if (down[i][j]) {
                cout << '.';
            }
            else {
                cout << '#';
            }
        }
        cout << endl;
    }
}
