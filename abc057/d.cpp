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

lli comb_table[51][51];


void cal() {
    for (int i = 0; i < 51; i++)
        comb_table[i][0] = 1;

    for (int j = 0; j < 51; j++)
        comb_table[j][j] = 1;


    for (int i = 2; i < 51; ++i) {
        for (int j = 1; j < 51 and j < i; ++j) {
            comb_table[i][j] = ( comb_table[ i-1 ][j] + comb_table[ i-1 ][ j-1 ] );
        }
    }
    return;
}
int main() {
    lli n, a, b;
    cin3(n, a, b);
    lli v[n];
    ncin1(n, v);

    sort(v, v+n, greater<lli>());
    map<lli, lli> m;
    REP(i, 0, n){
        m[v[i]]++;
    }

    cal();
    if (m[v[0]] >= a) {
        // ex. 5 2 3 3 3 3 3 3
        // 全部それで良い
        lli ans = 0;
        REP(i, a, min(m[v[0]]+1, b+1)) {
            //cout << m[v[0]] << "C" <<i << ": " << comb_table[m[v[0]]][i] << endl;
            //cout << comb_table[m[v[0]]][i] << endl;
            ans += comb_table[m[v[0]]][i];
        }
        cout << v[0] << endl;
        cout << ans << endl;
    }
    else {
        lli cnt = 0;
        lli total = 0;
        lli ans = 1;
        auto it = m.rbegin();
        for(; it != m.rend(); it++) {
            //cout << it->first << ": " << it->second << endl;
            cnt += it->second;
            if (cnt >= a) {
                total += it->first * (a - (cnt-it->second));
                //cout << it->second << endl;
                //cout << a - (cnt-it->second) << endl;
                //cout << comb_table[it->second][a - (cnt-it->second)] << endl;
                ans *= comb_table[it->second][a - (cnt-it->second)];
                break;
            }
            total += it->first * it->second;
        }
        //cout << (it)->first << endl; // 10
        //cout << (it)->second << endl; // 3

        cout.precision(20);
        cout << fixed << ((double)total) / a << endl;
        cout << ans << endl;
    }
}
