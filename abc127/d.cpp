#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(int i=init;i<n;i++)
#define REPE(i,init, n) for(int i=init;i<=n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    priority_queue<lli, vector<lli>, greater<lli> > que;
    lli ans = 0;
    lli n, m;
    cin >> n >> m;
    REP(i, 0, n) {
        lli a;
        cin >> a;
        que.push(a);
        ans += a;
    }

    vector<P> cb;
    REP(i, 0, m) {
        lli b, c;
        cin >> b >> c;
        cb.push_back(P(c, b));
    }
    sort(cb.rbegin(), cb.rend());
    REP(i, 0, cb.size()) {
        if (que.top() >= cb[i].first)
            break;
        REP(j, 0, cb[i].second) {
            lli num = que.top();
            if (num >= cb[i].first)
                break;
            que.pop();
            que.push(cb[i].first);
            ans = ans - num + cb[i].first;
        }
    }
    //while (!que.empty()) {
    //    cout << que.top() << endl;
    //    que.pop();
    //}

    cout << ans << endl;
}
