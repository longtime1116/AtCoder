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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;

map <P, vector<P>> G;
map <P, lli> counts;

int main() {
    lli n;
    cin1(n);
    lli none_zero_count = 0;
    REPE(i, 1, n) {
        lli prev;
        REPE(j, 1, n-1) {
            lli x;
            cin >> x;
            if (j != 1) {
                lli a, b;
                a = min(i, prev);
                b = max(i, prev);
                lli c, d;
                c = min(i, x);
                d = max(i, x);

                G[P(a, b)].push_back(P(c, d));
                counts[P(c,d)]++;
                if (counts[P(c,d)] == 1)
                    none_zero_count++;
            }
            prev = x;
        }
    }

    //REPIT(it, G) {
    //    P  p1 = it->first;
    //    cout << "(" << p1.first << ", " << p1.second << ")" << " => ";
    //    vector<P>  pv = it->second;
    //    for (lli i = 0; i < pv.size(); i++) {
    //        P p2 = pv[i];
    //        cout << "(" << p2.first << ", " << p2.second << ")" << "=>";
    //    }
    //    cout << endl;
    //}

    //lli ans = 0;
    //REP(i, 0, n*(n-1)/2) {
    //    bool updated = false;
    //    cout1(i);
    //    REPIT(it, G) {
    //        P  p = it->first;

    //        vector<P> pv = it->second;
    //        if (pv.size() == 0)
    //            continue;
    //        if (counts[p] != 0) {
    //            continue;
    //        }
    //        updated = true;
    //        ans++;
    //        cout << "(" << p.first << ", " << p.second << ")" << endl;
    //        // G[p] を巡回して、countsを減らしていく
    //        REP(j, 0, pv.size()) {
    //            cout << "hoge" << endl;
    //            counts[pv[j]]--;
    //            if (counts[pv[j]] == 0)
    //                none_zero_count--;
    //        }
    //        it->second.erase(it->second.begin(), it->second.end());
    //    }
    //    if (none_zero_count == 0)
    //        break;
    //    if (!updated) {
    //        cout << -1 << endl;
    //        return 0;
    //    }
    //}
    lli ans = 0;
    queue<P> que;
    REPIT(it, G) {
        P  p = it->first;
        if (counts[p] == 0)
            que.push(p);
    }
    while (true) {
        ans++;
        queue<P> que2;
        while (!que.empty()) {
            P p = que.front();
            que.pop();
            vector<P> pv = G[p];
            REP(i, 0, pv.size()) {
                counts[pv[i]]--;
                if (counts[pv[i]] == 0) {
                    none_zero_count--;
                    que2.push(pv[i]);
                }
            }
        }
        // que2 を que1 に移す
        while (!que2.empty()) {
            que.push(que2.front());
            que2.pop();
        }
        if (que.empty())
            break;
    }
    if (none_zero_count != 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
    //REP(i, 0, n*(n-1)/2) {
    //    bool updated = false;
    //    cout1(i);
    //    REPIT(it, G) {
    //        P  p = it->first;

    //        vector<P> pv = it->second;
    //        if (pv.size() == 0)
    //            continue;
    //        if (counts[p] != 0) {
    //            continue;
    //        }
    //        updated = true;
    //        ans++;
    //        cout << "(" << p.first << ", " << p.second << ")" << endl;
    //        // G[p] を巡回して、countsを減らしていく
    //        REP(j, 0, pv.size()) {
    //            cout << "hoge" << endl;
    //            counts[pv[j]]--;
    //            if (counts[pv[j]] == 0)
    //                none_zero_count--;
    //        }
    //        it->second.erase(it->second.begin(), it->second.end());
    //    }
    //    if (none_zero_count == 0)
    //        break;
    //    if (!updated) {
    //        cout << -1 << endl;
    //        return 0;
    //    }
    //}
}
