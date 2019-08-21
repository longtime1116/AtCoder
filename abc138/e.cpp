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
    lli sl = s.length();
    lli tl = t.length();

    map<char, vector<lli>> m;

    REP(i, 0, sl) {
        m[s[i]].push_back(i);
    }
    //REP(i, 0, sl) {
    //    vector<lli> x = m[s[i]];
    //    REP(j, 0, x.size()) {
    //        cout << x[j] << endl;
    //    }
    //}
    //REPIT(it, m) {
    //    cout << it->first << ": ";
    //    REP(i, 0, (it->second.size())) {
    //        cout << it->second[i] << ", ";
    //    }
    //    cout << endl;
    //}

    lli count = 0;
    lli pos = -1;
    lli cur = 0;
    while(cur < tl) {
        // ↓をやると、TLEになる。コピーに時間がかかりすぎる
        //vector<lli> vec = m[t[cur]];
        auto it = upper_bound(m[t[cur]].begin(), m[t[cur]].end(), pos);
        if (it == m[t[cur]].end()) {
            //cout << "if" << endl;
            //cout1(cur);
            if (pos == -1) {
                cout << -1 << endl;
                return 0;
            }
            count++;
            pos = -1;
        }
        else {
            //cout << "else" << endl;
            //cout1(cur);
            //cout1(*it);
            pos = *it;
            cur++;
        }
    }
    cout << count * sl + pos+1 << endl;
}
