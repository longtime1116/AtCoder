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
    string s;
    cin >> s;
    int len = s.length();
    lli maru = 0;
    REP(i, 0, len) {
        if (s[i] == 'o')
            maru++;
    }
    lli left = 15 - len;
    if (maru + left > 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
