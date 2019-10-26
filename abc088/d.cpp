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
typedef vector<lli> vlli;

int main() {
    lli h,w;
    cin2(h,w);
    string s[h+2];
    REPE(i,0,h+1) {
        if (i == 0) {
            s[i] = string(w+2, 'o');
            continue;
        }
        else if (i == h+1) {
            s[i] = string(w+2, 'o');
            continue;
        }
        string x;
        cin >> x;
        x = "o" + x + "o";
        s[i] = x;
    }

    lli ans = h*w;
    REPE(i,1,h) {
        //cout << s[i] <<endl;
        REPE(j,1,w) {
            if (s[i][j] == '#')
                ans--;
        }
    }


    lli lr[4] = {-1,0,1,0};
    lli ud[4] = {0,1,0,-1};
    bool done[h+2][w+2] = {false};
    queue<tup> que;
    // row, column, 何手目か
    que.push(make_tuple(1,1,1));
    done[1][1] = true;
    bool is_ok = false;
    while (!que.empty()) {
        lli r, c, n;
        tie(r, c, n) = que.front();
        que.pop();
        if (r == h && c == w) {
            ans -= n;
            is_ok = true;
            break;
        }
        // 上下左右に移動
        REP(i,0,4) {
            lli next_r = r + ud[i];
            lli next_c = c + lr[i];
            // 上下左右の境界チェック
            if (next_r <= 0 || next_r >= h+1)
                continue;
            if (next_c <= 0 || next_c >= w+1)
                continue;

            if (done[next_r][next_c])
                continue;
            if (s[next_r][next_c] == '#')
                continue;
            done[next_r][next_c] = true;
            que.push(make_tuple(next_r, next_c, n+1));
        }
    }
    if (is_ok)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
