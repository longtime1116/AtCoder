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
    cin.tie(0);
    ios::sync_with_stdio(false);

    lli n,c;
    cin2(n,c);
    lli x[n+2];
    lli v[n+1];
    ncin2_1(n,x,v);
    x[0] = 0;
    x[n+1] = c;

    lli cal_r[n+1];
    lli cal_l[n+2];
    cal_r[0] = 0;
    cal_l[n+1] = 0;

    lli ans = -LLONG_MAX;
    // 右に行く
    REP(i,0,n) {
        // i から i + 1 に行く
        cal_r[i+1] = cal_r[i] + v[i+1] - (x[i+1]-x[i]);
        ans = max(ans, cal_r[i+1]);
        //cout2(i+1, cal_r[i+1]);
    }
    // 左に行く
    REPE_R(i,n+1,2) {
        // i から i - 1 に行く
        cal_l[i-1] = cal_l[i] + v[i-1] - (x[i]-x[i-1]);
        ans = max(ans, cal_l[i-1]);
        //cout2(i-1, cal_l[i-1]);
    }
    //cout1(ans);
    // まず左に行き、その後戻って右に行く
    lli max_go2 = 0;
    REPE(i,2,n) {
        // 左に行き i まで行く
        lli cost_go = cal_l[i];
        // i から 0 に戻る
        lli cost_back = c - x[i];
        // 0 から i-1 までの最もいい感じのところに行く
        max_go2 = max(max_go2, cal_r[i-1]);
        ans = max(ans, cost_go - cost_back + max_go2);
    }


    // まず右に行き、その後戻って左に行く
    max_go2 = 0;
    REPE_R(i,n-1,1) {
        // 右に行き i まで行く
        lli cost_go = cal_r[i];
        // i から 0 に戻る
        lli cost_back = x[i];
        // 0 から i+1 までの最もいい感じのところに行く
        max_go2 = max(max_go2, cal_l[i+1]);
        ans = max(ans, cost_go - cost_back + max_go2);
    }
    if (ans < 0)
        cout << 0 << endl;
    else
        cout << ans << endl;
}
