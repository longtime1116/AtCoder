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

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n;
    cin1(n);
    lli a[n];
    ncin1(n, a);
    map<lli, lli> m;
    REP(i, 0, n) {
        m[a[i]]++;
    }
    if (m.size() > 3) {
        cout << "No" << endl;
        return 0;
    }
    else if (m.size() == 3) {
        lli num = m[a[0]];
        REPIT(it, m) {
            if (it->second != num) {
                cout << "No" << endl;
                return 0;
            }
        }
        lli x[3];
        lli ind = 0;
        REPIT(it, m) {
            //printf("key: %d, value: %d\n", it->first, it->second);
            x[ind] = it->first;
            //cout << x[ind] << endl;
            ind++;
        }

        if (((x[0] ^ x[1]) == x[2]) &&
                ((x[1] ^ x[2]) == x[0])&&
                ((x[2] ^ x[0]) == x[1])) {
            cout << "Yes" << endl;
            return 0;
        }
        cout << "No" << endl;

    }
    else if (m.size() == 2) {
        lli x_f[2];
        lli x_s[2];
        lli ind = 0;
        REPIT(it, m) {
            x_f[ind] = it->first;
            x_s[ind] = it->second;
            ind++;
        }
        if (x_f[0] != 0) {
            cout << "No" << endl;
            return 0;
        }
        if (x_s[0] * 2 != x_s[1]) {
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        return 0;
    }
    else if (m.size() == 1) {
        REPIT(it, m) {
            if (it->first != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }

}
