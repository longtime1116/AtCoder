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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;

lli h, w;
string s[501];
bool done[501][501][3];


int main() {
    cin2(h, w);

    REP(i, 0, h) {
        cin >> s[i];
    }

    lli si, sj;
    lli gi, gj;
    si = sj = gi = gj = -1;
    REP(i, 0, h) {
        REP(j, 0, w) {
            if (s[i][j] == 's') {
                si = i;
                sj = j;
            }
            if (s[i][j] == 'g') {
                gi = i;
                gj = j;
            }
        }
    }

    queue<tup> que;
    que.push(tup(si, sj, 0));
    lli move_r[] = {-1, 1, 0, 0};
    lli move_c[] = {0, 0, -1, 1};
    while (!que.empty()) {
        lli r, c, x;
        tie(r, c, x) = que.front();
        que.pop();
        if (x > 2)
            continue;
        bool is_done = false;
        REPE(i, 0, x) {
            if (done[r][c][i])
                is_done = true;
        }
        if (is_done)
            continue;
        done[r][c][x] = true;
        //cout3(r, c, x);
        REP(i, 0, 4) {
            if (r+move_r[i] < 0 || r+move_r[i] > h-1 ||
                c+move_c[i] < 0 || c+move_c[i] > w-1)
                continue;
            lli next_x = x;
            if (s[r+move_r[i]][c+move_c[i]] == '#')
                next_x++;

            que.push(tup(r+move_r[i], c+move_c[i], next_x));
        }
    }
    REP(i, 0, 3) {
        if (done[gi][gj][i]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}
