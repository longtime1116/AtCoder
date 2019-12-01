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

bool exist[10][10][10];

int main() {
    lli n;
    cin1(n);
    string s;
    cin1(s);
    vlli x[10];
    REP(i,0,n) {
        x[s[i]-'0'].push_back(i);
    }

    lli ans = 0;
    //REP(i,0,x[3].size()) {
    //    cout << x[3][i] << endl;
    //}
    REP(i,0,10) {
        lli loc = -1;
        // i がある最初を探す
        auto it1 = lower_bound(x[i].begin(), x[i].end(), loc+1);
        if (it1 == x[i].end())
            continue;
        loc = (*it1);
        //cout2(i, loc);

        REP(j,0,10) {
            lli loc2 = loc;
            auto it2 = lower_bound(x[j].begin(), x[j].end(), loc2+1);
            if (it2 == x[j].end())
                continue;
            loc2 = (*it2);
            //cout3(i, j, loc2);
            REP(k,0,10){
                lli loc3 = loc2;
                auto it3 = lower_bound(x[k].begin(), x[k].end(), loc2+1);
                if (it3 == x[k].end())
                    continue;
                ans++;
                //cout3(i,j,k);
            }
        }
    }
    cout << ans << endl;
}
