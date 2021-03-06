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
#define ncin1(n, x)         REP(i, 0, n) {cin1(x[i]);}
#define ncin2(n, x, y)      REP(i, 0, n) {cin2(x[i], y[i]);}
#define ncin3(n, x, y, z)   REP(i, 0, n) {cin3(x[i], y[i], z[i]);}

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

vector<lli> G[51];
bool done[51][51];

bool rec(lli origin, lli from, lli to) {
    if (done[from][to])
        return false;
    if (to == origin)
        return true;

    done[to][from] = done[from][to] = true;
    REP(i,0,G[to].size()) {
        if (G[to][i] == from)
            continue;
        if (rec(origin, to, G[to][i])) {
            return true;
        }
    }
    return false;

}
int main() {
    lli n,m;
    cin2(n,m);
    REP(i,0,m) {
        lli a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    lli ans = 0;
    REPE(i,1,n) {
        REP(j,0,G[i].size()) {
            REPE(k,1,n) {
                REPE(l,1,n) {
                    done[l][k] = done[k][l] = false;
                }
            }

            if (i > G[i][j])
                continue;
            if (rec(i, i,G[i][j])) {
                //cout2(i,G[i][j])
                ans++;
            }
        }
    }
    cout << m - ans << endl;
}
