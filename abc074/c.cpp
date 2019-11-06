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

double dp_suger[6001]; // dp[i] := i グラムの溶液を実現するときの最大の濃度のための砂糖
double dp_water[6001]; // dp[i] := i グラムの溶液を実現するときの最大の濃度のための水


double calc(double a, double b){
    if (a+b == 0)
        return 0;
    return a * 100 / (a+b);
}

int main() {
    lli a,b,c,d,e,f;
    cin2(a,b);
    a *= 100;
    b *= 100;
    cin2(c,d);
    cin2(e,f);

    REPE(i,0,f) {
        // a を使う場合
        double con = calc(dp_suger[i+a], dp_water[i+a]);
        if (con <= calc(dp_suger[i], dp_water[i] + a)) {
            dp_suger[i+a] = dp_suger[i];
            dp_water[i+a] = dp_water[i] + a;
        }
        // b を使う場合
        con = calc(dp_suger[i+b], dp_water[i+b]);
        if (con <= calc(dp_suger[i], dp_water[i] + b)) {
            dp_suger[i+b] = dp_suger[i];
            dp_water[i+b] = dp_water[i] + b;
        }

        // c を使う場合
        con = calc(dp_suger[i+c], dp_water[i+c]);
        //cout3(i+c, con, calc(dp_suger[i]+c, dp_water[i]));
        if (con <= calc(dp_suger[i]+c, dp_water[i]) &&
            calc(dp_suger[i]+c, dp_water[i]) <= calc(e, 100)) {
            dp_suger[i+c] = dp_suger[i] + c;
            dp_water[i+c] = dp_water[i];
        //cout2(dp_suger[i+c], dp_water[i+c]);
        }

        // d を使う場合
        con = calc(dp_suger[i+d], dp_water[i+d]);
        if (con <= calc(dp_suger[i]+d, dp_water[i]) &&
            calc(dp_suger[i]+d, dp_water[i]) <= calc(e, 100)) {
            dp_suger[i+d] = dp_suger[i] + d;
            dp_water[i+d] = dp_water[i];
        }
    }
    double anscon = 0;
    lli ans_all = 0;
    lli ans_suger = 0;
    REPE(i,0,f) {
        double x = calc(dp_suger[i], dp_water[i]);
        if (x >= anscon) {
            anscon = x;
            ans_all = dp_suger[i] + dp_water[i];
            ans_suger = dp_suger[i];
        }
    }
    cout << ans_all << " " << ans_suger << endl;
}
