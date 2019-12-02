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



// m=3として、
// m1, m2, m3 が選ばれたとする
//
//      Xm1 Ym1 Zm1
//      Xm2 Ym2 Zm2
//      Xm3 Ym3 Zm3
//
// このときの求めるべき値は、
//
//      abs(Xm1 + Xm2 + Xm3) + abs(Ym1 + Ym2 + Ym3) + abs(Zm1 + Zm2 + Zm3)
//
// 例えば Y のところが負でほかは正だとすると、
//
//      (Xm1 + Xm2 + Xm3) - (Ym1 + Ym2 + Ym3) + (Zm1 + Zm2 + Zm3)
//
// 式変形して
//
//      (Xm1 - Ym1 + Zm1) + (Xm2 - Ym2 + Zm2) + (Xm3 - Ym3 + Zm3)
//
// これの最大値を出したいのであれば、Xmi + Ymi + Zmi の合計値が大きい順に m 個取れば良い
//
// あとはこれを 8 通りやって最大のものを選べば良い
//

int main() {
    lli n,m;
    cin2(n,m);
    lli x[n];
    lli y[n];
    lli z[n];
    ncin3(n,x,y,z);

    lli ans = 0;
    REP(i,0,8) {
        lli sum[n];
        REP(j,0,n) {
            lli cur_sum = 0;
            lli values[] = {x[j], y[j], z[j]};
            REP(k,0,3) {
                if (i & (1<<k)) {
                    cur_sum += values[k];
                }
                else {
                    cur_sum -= values[k];
                }
            }
            sum[j] = cur_sum;
        }
        sort_r(sum, sum+n);
        lli cur_ans = 0;
        REP(j,0,m) {
            cur_ans += sum[j];
        }
        ans = max(ans, cur_ans);
    }
    cout << ans << endl;

}
