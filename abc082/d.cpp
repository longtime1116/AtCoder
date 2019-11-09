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

bool dp_lr[16001][16001]; // dp_lr[i][j] := i回目が終わった時点でj地点へ到達可能かどうかjは8000がゼロとする
bool dp_ud[16001][16001]; // dp_lr[i][j] := i回目が終わった時点でj地点へ到達可能かどうかjは8000がゼロとする
int main() {
    string s;
    lli x,y;
    cin3(s,x,y);
    vlli lr;
    vlli ud;
    bool is_lr = true;
    lli cur = 0;
    REP(i,0,s.length()) {
        if (is_lr && s[i] == 'T') {
            // lr から ud へと変化
            if (cur != 0)
                lr.push_back(cur);
            cur = 0;
            is_lr = !is_lr;
        }
        else if (!is_lr && s[i] == 'T') {
            // ud から lr へと変化
            if (cur != 0)
                ud.push_back(cur);
            cur = 0;
            is_lr = !is_lr;
        }
        else {
            // 続行
            cur++;
        }
    }
    if (cur != 0) {
        if (is_lr) {
            lr.push_back(cur);
        }
        else {
            ud.push_back(cur);
        }
    }
    //REP(i,0,lr.size()) {
    //    cout1(lr[i]);
    //}
    //REP(i,0,ud.size()) {
    //    cout1(ud[i]);
    //}


    // lr について解決
    // lr については、s[0] が F であれば、lr[0] は必ず右向き
    lli start = 0;
    if (s[0] == 'F') {
        start = 1;
        dp_lr[1][8000+lr[0]] = true;
    }
    else
        dp_lr[0][8000] = true;
    REP(i,start,lr.size()) {
        // lr[i] 分動かすやつを、true のものに対して行っていく
        REP(j,0, 16001) {
            if (dp_lr[i][j]) {
                dp_lr[i+1][j+lr[i]] = dp_lr[i+1][j-lr[i]] = true;
            }
        }
    }
    dp_ud[0][8000]= true;
    REP(i,0,ud.size()) {
        // ud[i] 分動かすやつを、true のものに対して行っていく
        REP(j,0, 16001) {
            if (dp_ud[i][j]) {
                dp_ud[i+1][j+ud[i]] = dp_ud[i+1][j-ud[i]] = true;
            }
        }
    }
    //REP(i,0,16000) {
    //    if (dp_lr[lr.size()][i])
    //        cout1(i);
    //}
    //cout << endl;
    //REP(i,0,16000) {
    //    if (dp_ud[ud.size()][i])
    //        cout1(i);
    //}
    if (!dp_lr[lr.size()][x+8000] || !dp_ud[ud.size()][y+8000]) {
        cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;
}
