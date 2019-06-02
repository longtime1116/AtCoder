#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n;
    cin >> n;
    map<string, int> s;
    REP(i, 0, n) {
        string x;
        cin >> x;
        auto it = s.find(x);
        if (it == s.end())
            s.insert(make_pair(x, 1));
        else
            it->second++;
    }
    lli m;
    cin >> m;
    REP(i, 0, m) {
        string x;
        cin >> x;
        auto it = s.find(x);
        if (it != s.end())
            it->second--;
    }
    int ans = 0;
    REPIT(it, s) {
        ans = max(it->second, ans);
    }
    cout << ans << endl;
}
