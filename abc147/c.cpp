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
    lli n;
    cin1(n);
    lli a[n];
    lli x[n][n];
    lli y[n][n];

    REP(i,0,n) {
        cin >> a[i];
        REP(j,0,a[i]) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }


    lli ans = 0;
    REPE(state,0,(1<<n)-1) {
        // 1 だと正直、-1だと不親切
        lli is_ok[n] = {0};
        lli hoge = state;
        lli cur = 0;
        lli num = 0;
        while (true) {
            if (hoge == 0)
                break;
            if (hoge & 1) {
                is_ok[cur] = 1;
                num++;
            }
            else
                is_ok[cur] = 0;
            cur++;
            hoge /= 2;
        }
        //cout1(state);
        //cout3(is_ok[0], is_ok[1], is_ok[2]);
        REP(i,0,n) {
            // i 人目の証言を反映させる
            REP(j,0,a[i]) {
                //cout2(i,j);
                //cout3(is_ok[i], y[i][j], is_ok[x[i][j]]);
                if (is_ok[i] == 0)
                    continue;
                if (y[i][j] == 1 && is_ok[x[i][j]] == 1)
                    continue;
                if (y[i][j] == 0 && is_ok[x[i][j]] == 0)
                    continue;
                //cout << "hoge" << endl;


                //cout2(i,j);
                //cout3(x[i][j],is_ok[x[i][j]], y[i][j]);
                //cout << "hpge" << endl;
                goto NEXT;
            }
        }
        //cout1(state);
        ans = max(ans, num);
NEXT:
        //cout << endl;
        lli ggg = 0;
    }
    cout << ans << endl;
    return 0;
}
