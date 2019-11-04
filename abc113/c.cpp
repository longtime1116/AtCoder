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
#define coutt(t)         cout << #t << ":" <<  " (" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;
typedef vector<lli> vlli;

class Compare
{
public:
    bool operator()(tup t1, tup t2) {
        lli a1,b1,c1;
        tie(a1,b1,c1) = t1;
        lli a2,b2,c2;
        tie(a2,b2,c2) = t2;

        return c1 < c2;
    }
};


int main() {
    lli n,m;
    cin2(n,m);
    tup t[m];
    REP(i,0,m) {
        lli pi, yi;
        cin >> pi >> yi;
        t[i] = tup(pi,yi,i);
    }
    sort(t, t+m);
    lli cur_pref = get<0>(t[0]);
    lli cur_id = 1;
    REP(i,0,m) {
        lli pref = get<0>(t[i]);
       if (cur_pref != pref) {
            cur_pref = pref;
            cur_id = 1;
        }
        get<1>(t[i]) = cur_id;
        cur_id++;
    }
    sort(t, t+m, Compare());
    REP(i,0,m) {
        lli a,b,c;
        tie(a,b,c) = t[i];
        string a_str = to_string(a);
        string b_str = to_string(b);
        string a_pre = string(6-a_str.length(), '0');
        string b_pre = string(6-b_str.length(), '0');
        cout << a_pre + a_str + b_pre + b_str << endl;


    }

}
