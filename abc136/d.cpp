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
    string s;
    cin1(s);
    lli len = s.length();
    if (len == 2) {
        cout << "1 1" << endl;
        return 0;
    }
    lli ans[len] = {0};

    vector<lli> rl_inds_r;
    vector<lli> rl_inds_l;
    REP(i, 0, len-1) {
        if (s[i] == 'R' && s[i+1] == 'L') {
            rl_inds_r.push_back(i);
            rl_inds_l.push_back(-(i+1));
        }
    }
    sort(rl_inds_l.begin(), rl_inds_l.end());

    REP(i, 0, len) {
        if (s[i] == 'R') {
            // rl のやつか？
            if (binary_search(rl_inds_r.begin(), rl_inds_r.end(), i)) {
                ans[i]++;
            }
            else {
                auto it = upper_bound(rl_inds_r.begin(), rl_inds_r.end(), i);
                lli ind = *it;
                if ((ind - i) % 2 == 0) {
                    ans[ind]++;
                }
                else {
                    ans[ind+1]++;
                }
            }


        }
        else {
            if (binary_search(rl_inds_l.begin(), rl_inds_l.end(), -i)) {
                ans[i]++;
            }
            else {
                auto it = upper_bound(rl_inds_l.begin(), rl_inds_l.end(), -i);
                lli ind = -(*it);
                if ((i - ind) % 2 == 0) {
                    ans[ind]++;
                }
                else {
                    ans[ind-1]++;
                }
            }
        }
    }
    REP(i, 0, len) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
