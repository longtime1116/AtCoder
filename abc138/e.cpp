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
    string s, t;
    cin2(s, t);
    lli j = 0;
    lli cur = 0;
    lli count = 0;
    lli ans = 0;
    lli sl = s.length();
    lli tl = t.length();

    map<char, vector<lli>> m;

    REP(i, 0, sl) {
        m[s[i]].push_back(i);
    }
    REP(i, 0, 26) {
        sort(m['a'+i].begin(), m['a'+i].end());

    }

    REPIT(it, m) {
        cout << it->first << ": ";
        REP(i, 0, (it->second.size())) {
            cout << it->second[i] << ", ";
        }
        cout << endl;
    }

    while (true) {
        ans++;
        if (s[j] == t[cur]) {
            count = 0;
            cur++;
            if (cur == tl)
                break;
        }

        count++;
        j = (j + 1) % sl;
        if (count == sl+1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
