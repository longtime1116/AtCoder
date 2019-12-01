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
    lli n,C;
    cin2(n,C);
    lli d[C][C];
    REP(i,0,C) {
        REP(j,0,C) {
            cin >> d[i][j];
        }
    }
    lli c[n][n];
    REP(i,0,n) {
        REP(j,0,n) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    // 0 mod 3 となる位置をすべて i 色にしたときのコスト
    lli cost_0[C] = {0};
    lli cost_1[C] = {0};
    lli cost_2[C] = {0};

    REP(color,0,C) {
        // color で塗ったときの 0 1 2 のコストを計算する
        REP(row,0,n)  {
            REP(col,0,n)  {
                lli target = (row + col) % 3;
                //cout1(color);
                //cout3(row,col,target);
                if (target == 0) {
                    if (c[row][col] != color) {
                        cost_0[color] += d[c[row][col]][color];
                        //cout1(d[c[row][col]][color]);
                        //cout1(cost_0[color]);
                    }
                }
                else if (target == 1) {
                    if (c[row][col] != color) {
                        cost_1[color] += d[c[row][col]][color];
                        //cout1(d[c[row][col]][color]);
                        //cout1(cost_1[color]);
                    }
                }
                else {
                    if (c[row][col] != color) {
                        cost_2[color] += d[c[row][col]][color];
                        //cout1(d[c[row][col]][color]);
                        //cout1(cost_2[color]);
                    }
                }
            }
        }
    }
    P c0[C];
    P c1[C];
    P c2[C];
    REP(i,0,C) {
        c0[i] = P(cost_0[i], i);
    }
    REP(i,0,C) {
        c1[i] = P(cost_1[i], i);
    }
    REP(i,0,C) {
        c2[i] = P(cost_2[i], i);
    }
    sort(c0, c0 + C);
    sort(c1, c1 + C);
    sort(c2, c2 + C);

    lli val = LLONG_MAX;
    REP(i,0,3) {
        REP(j,0,3) {
            REP(k,0,3) {
                // c0[i] と c1[j] と c2[k] を使ったときの最小値を出す

                if (c0[i].second != c1[j].second && c1[j].second != c2[k].second && c2[k].second != c0[i].second) {
                    if (val > c0[i].first + c1[j].first + c2[k].first) {
                        val = c0[i].first + c1[j].first + c2[k].first;
                    }
                }
            }
        }
    }
    cout << val << endl;
}
