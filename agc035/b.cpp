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

set<lli> G[100001];
//bool done[100001];

struct edge {
    lli to;
};

set<lli> ANS[100001];

int main() {
    lli n, m;
    cin2(n, m);
    if (m % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, 0, m) {
        lli a, b;
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }

    // この方法だと不十分で、全域木の葉から順番に決めていくようにしなければならない
    lli cur = 1;
    bool updated = false;
    lli done = 0;
    while (true) {
        if (cur == n+1) {
            if (done == n) {
                break;
            }
            else if (updated) {
                cur = 1;
                updated = false;
                continue;
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
        lli es = G[cur].size();
        if (es % 2 != 0 || es == 0) {
            cur++;
            continue;
        }
        else {
            //cout << "cur: " << cur << endl;
            vector<lli> ers;
            REPIT(it, G[cur]) {
                //cout << *it << endl;
                ANS[cur].insert(*it);
                ers.push_back(*it);
            }
            REP(i, 0, ers.size()) {
                G[cur].erase(ers[i]);
                G[ers[i]].erase(cur);
                if (G[ers[i]].size() == 0) {
                    done++;
                }
            }
            updated=true;
            done++;
        }
        cur++;
    }
    REPE(i, 1, n) {
        REPIT(it, ANS[i]) {
            cout << i << " " << *it << endl;
        }
    }
}
