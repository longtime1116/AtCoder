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

// dp[i] := i のときの期待値
//          ただし、iは状態をbitで表す整数
//double dp[2^17];

lli n;
lli state[19];
bool exist[19];
lli left_i;
lli right_i;

// val 状態で left_i+i に投げる
double rec(lli val, lli i, double *dp) {
    if (val == 0)
        return 0;
    if (dp[val] != 0)
        return dp[val];

    double exist_count = 0;
    REP(i,-1,2) {
        if (exist[left_i+i])
            exist_count += 1;
    }
    double l,m,r;
    // 左
    if (exist[left_i+i-1])
        l = rec(val - (1<<(right_i-left_i-i+1)), i-1, dp);
    else
        l = 0;
    // 真ん中
    if (exist[left_i+i])
        m = rec(val - (1<<(right_i-left_i-i)), i, dp);
    else
        m = 0;
    // 右
    if (exist[left_i+i+1])
        r = rec(val - (1<<(right_i-left_i-i-1)), i+1, dp);
    else
        r = 0;

    cout1(val);
    cout<<"left" << endl;
    cout1(left_i+i-1);
    cout1(l);
    cout<<"middle" << endl;
    cout1(left_i+i);
    cout1(m);
    cout<<"right" << endl;
    cout1(left_i+i+1);
    cout1(r);
    dp[val] = (l+m+r+1)/exist_count;
    cout2(val, dp[val]);
    cout<<endl;
    return dp[val];
}
int main() {
    cin1(n);
    lli x[n];
    // x[i] は 1〜16 の値をとるとする
    REP(i,0,n) {
        cin >> x[i];
        x[i]+=2;
    }
    sort(x, x+n);
    // x
    // 2,4,8,9,10,11
    // 入力自体は、0,2,6,7,8,9

    REP(i,0,n) {
        state[x[i]-1]++;
        state[x[i]]++;
        state[x[i]+1]++;
        exist[x[i]] = true;
    }
    REP(i,0,19) {
        cout1(state[i]);
    }
    cout<<endl;
    REP(i,0,19) {
        cout1(exist[i]);
    }
    // 分割した上で一個ずつ処理する
    lli next_start = 0;
    double ans = 0;
    {
        double ans_cur = DBL_MAX;
        // 影響のあるところだけを抜き出す
        vector<lli> cur;
        bool start = false;
        REP(i,next_start,19){
            if (!start) {
                if (state[i] != 0) {
                    start = true;
                    left_i = i;
                }
            }
            else if (state[i] == 0) {
                break;
            }
            right_i = i;
        }
        cout2(left_i, right_i);
        lli val = 0;
        REPE(i,left_i,right_i) {
            val = val << 1;
            if (exist[i])
                val += 1;
        }
        cout1(val);
        // その範囲で、すべての箇所から初めて一番期待値が低いやつ選ぶ
        REPE(i,0,right_i-left_i) {
            double dp[2^19] = {0};
            cout << i << "====================================" << endl;;
            ans_cur = min(ans, rec(val, i, dp));
            cout1(dp[val]);
            cout1(ans_cur);
        }
        ans += ans_cur;

        next_start = right_i+1;
    }
    // 全部足す

    cout << ans << endl;
}
