#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
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
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n;
    cin1(n);
    string s, t;
    cin >> s >> t;

    vector<int> ary;
    char cur, prev;
    prev = s[0];
    REPE(i, 1, n-1) {
        prev = s[i-1];
        cur = s[i];
        if (cur == prev) {
            ary.push_back(2);
            i++;
        }
        else {
            ary.push_back(1);
        }
    }
    if (s[n-1] != s[n-2]) {
        ary.push_back(1);
    }
    //ncout1(ary.size(), ary);
    lli mod = 1000000007;
    lli ans;
    if (ary[0] == 2)
        ans = 6;
    else
        ans = 3;
    REP(i, 0, ary.size()-1) {
        int cur = ary[i];
        int next = ary[i+1];
        if (cur == 1 && next == 1) {
            ans = ans * 2 % mod;
        }
        else if (cur == 1 && next == 2) {
            ans = ans * 2 % mod;
        }
        else if (cur == 2 && next == 1) {
        }
        else {
            ans = ans * 3 % mod;
        }
    }
    cout << ans << endl;
}
