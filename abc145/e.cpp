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
#define ncinp(n, p)         REP(i,0,n) { lli p1,p2; cin >> p1 >> p2; p[i] = P(p1, p2); }
#define ncin1_1(n, x)       REPE(i, 1, n) {cin1(x[i]);}
#define ncin2_1(n, x, y)    REPE(i, 1, n) {cin2(x[i], y[i]);}
#define ncin3_1(n, x, y, z) REPE(i, 1, n) {cin3(x[i], y[i], z[i]);}
#define ncinp_1(n, p)       REPE(i,1,n) { lli p1,p2; cin >> p1 >> p2; p[i] = P(p1, p2); }

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


lli dp[3001][6001]; // i 個目まで使える状態で、j 分での最大の幸福度

// firstだけ見て小さい順
class OnlyFirstLessCompare
{
public:
    bool operator()(P n1, P n2) {
        return n1.first<=n2.first;
    }
};

int main() {
    lli n,t;
    cin2(n,t);
    P p[n+1];
    ncinp_1(n,p);
    sort(p+1, p+n+1, OnlyFirstLessCompare());
    //REPE(i,1,n) {
    //    coutp(p[i]);
    //}

    REPE(i,1,n) {
        REPE(j,1,t+p[n].first-1) {
            if (j - p[i].first >= 0 && j - p[i].first < t) {
                dp[i][j] = max({dp[i][j-1], dp[i-1][j], dp[i-1][j-p[i].first] + p[i].second});
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    lli ans = 0;
    cout << dp[n][t+p[n].first-1] << endl;
}


