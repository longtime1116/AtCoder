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
    map<char, int> m;
    REP(i, 0, 4) {
        m[s[i]]++;
    }
    REP(i, 0, 4) {
        if (m[s[i]] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
            cout << "Yes" << endl;

}
