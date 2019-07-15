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
    string s;
    cin1(s);

    lli r_cnt = 0;
    lli l_cnt = 0;
    lli status = 0;//1でr継続中、-1でl継続中、0は無
    REP(i, 0, s.length()) {
        if (status == 0) {
            if (s[i] == ')'){
                r_cnt++;
                status = 1;
            }
            else {
                l_cnt++;
                status = -1;
            }
        }
        else if (status == 1) {
            if (s[i] == ')') {
                r_cnt++;
            }
            else {
                status = -1;
                l_cnt++;
            }
        }
        else if (status == -1) {
            if (s[i] == ')') {
                l_cnt--;
                if (l_cnt == 0) {
                    status = 0;
                }
            }
            else {
                l_cnt++;
            }
        }
    }
    //cout << l_cnt << endl;
    REP(i, 0, r_cnt) {
        cout << '(';
    }
    cout << s;
    REP(i, 0, l_cnt) {
        cout << ')';
    }
    cout << endl;
}
