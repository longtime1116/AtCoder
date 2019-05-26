#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<string, lli> P;

int main() {
    lli n;
    cin >> n;
    string s[n];
    lli p[n];
    vector <P> pr;
    REP(i, 0, n) {
        cin >> s[i] >> p[i];
        ostringstream sout;
        sout << std::setfill('0') << std::setw(3) << 999-p[i];
        string x = sout.str();
        s[i] += x;
        pr.push_back(P(s[i], i+1));
    }
    sort(pr.begin(), pr.end());
    REPIT(it,pr) {
        //cout << (*it).first << endl;
        cout << (*it).second << endl;
    }


}
