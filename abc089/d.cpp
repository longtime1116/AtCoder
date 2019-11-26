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

P table[90001];
lli costs[90001];
int main() {
    lli h,w,d;
    cin3(h,w,d);
    //cout3(h,w,d);
    lli a[h+1][w+1];
    REPE(i,1,h) {
        REPE(j,1,w) {
            cin >> a[i][j];
            table[a[i][j]] = P(i,j);
        }
    }
    lli q;
    cin1(q);
    lli l[q];
    lli r[q];
    ncin2(q, l, r);


    //REPE(i,1,d) {
    //    lli total = 0;
    //    for(lli j = i; j <= h*w; j += d) {
    //        lli cur = 
    //        // i => j のコストを保存する
    //        cost[j] = 100;
    //    }
    //}
    REPE(from,1,h*w) {
        lli to = from + d;
        if (to > h*w)
            break;
        // from => to を計算
        P f = table[from];
        P t = table[to];
        lli cur_cost = abs(f.first - t.first) + abs(f.second - t.second);
        costs[to] = costs[from] + cur_cost;
    }
    //REP(i,1,h*w) {
    //    cout2(i,costs[i]);
    //}

    REP(i,0,q) {
        cout << costs[r[i]] - costs[l[i]] << endl;
    }
}


// 1 => 4 => 7 => 10
// 1 => 4: 8
// 1 => 7: 15
// 1 => 10: 30
//
//
//
//13  25  7 15 17
//16  22 20  2  9
//14  11 12  1 19
//10   6 23  8 18
// 3  21  5 24  4
