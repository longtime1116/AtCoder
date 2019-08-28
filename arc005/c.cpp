#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

// input
#define cin1(x)             cin >> x
#define cin2(x, y)          cin >> x >> y
#define cin3(x, y, z)       cin >> x >> y >> z
#define ncin1(n, x)         REP(i, 0, n) {cin1(x[i]);}
#define ncin2(n, x, y)      REP(i, 0, n) {cin2(x[i], y[i]);}
#define ncin3(n, x, y, z)   REP(i, 0, n) {cin3(x[i], y[i], z[i]);}

// output
#define cout1(x)         cout << #x << ": " << x << endl;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli h, w;
string s[501];
bool done[501][501];

bool rec(lli r, lli c, lli left) {
    if (done[r][c])
        return false;

    if (left == -1)
        return false;

    if (s[r][c] == 'g')
        return true;

    //cout << "r: " << r << ", c: " << c << ", left: " << left << endl;
    done[r][c] = true;

    // left
    if (c > 0) {
        if (s[r][c-1] == '#') {
            if (rec(r, c-1, left-1))
                return true;
        }
        else {
            if (rec(r, c-1, left))
                return true;
        }
    }
    // right
    if (c < w-1) {
        if (s[r][c+1] == '#') {
            if (rec(r, c+1, left-1))
                return true;
        }
        else {
            if (rec(r, c+1, left))
                return true;
        }
    }
    // up
    if (r < h-1) {
        if (s[r+1][c] == '#') {
            if (rec(r+1, c, left-1))
                return true;
        }
        else {
            if (rec(r+1, c, left))
                return true;
        }
    }
    // down
    if (r > 0) {
        if (s[r-1][c] == '#') {
            if (rec(r-1, c, left-1))
                return true;
        }
        else {
            if (rec(r-1, c, left))
                return true;
        }
    }
    done[r][c] = false;
    return false;
}

int main() {
    cin2(h, w);

    REP(i, 0, h) {
        cin >> s[i];
    }

    REP(i, 0, h) {
        REP(j, 0, w) {
            if (s[i][j] == 's') {
                if (rec(i, j, 2))
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                return 0;
            }
        }
    }

}
