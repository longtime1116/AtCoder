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

bool is_checked[1002][1002];
char c[1002][1002];


lli dfs(lli row, lli col) {
    if (is_checked[row][col]) {
        return 0;
    }
    is_checked[row][col] = true;

    if (c[row][col] != 'o') {
        return 0;
    }
    lli count = 1;
    REPE(i, row-1, row+1) {
        REPE(j, col-1, col+1) {
            if (i == row && j == col)
                continue;
            if (c[i][j] == 'o') {
                count += dfs(i, j);
            }
        }
    }

    return count;

}

char check(lli count) {

    REP(i, 1, 144) {
        if (12 * i * i == count)
            return 'a';
        else if (16 * i * i == count)
            return 'b';
        else if (11 * i * i == count)
            return 'c';
    }
    return 0;
}

int main() {
    lli h, w;
    cin2(h, w);

    REPE(i, 1, h) {
        REPE(j, 1, w) {
            cin >> c[i][j];
        }
    }

    lli ansa, ansb, ansc;
    ansa = ansb = ansc = 0;
    REPE(i, 1, h) {
        REPE(j, 1, w) {
            lli count = dfs(i, j);
            if (count == 0)
                continue;
            //cout1(count);
            char c = check(count);
            if (c == 'a')
                ansa++;
            else if (c == 'b')
                ansb++;
            else if (c == 'c')
                ansc++;
        }
    }
    cout << ansa << " " << ansb << " " << ansc << endl;
}
