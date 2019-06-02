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
    lli len = s.length();
    lli ans = 0;
    lli i = 0;
    lli a_count = 0;
    while (true) {
        if (i+2>= len)
            break;

        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            // チェンジしてインクリメント
            s[i] = 'B';
            s[i+1] = 'C';
            s[i+2] = 'A';
            ans += 1;
            //cout << "ans added" << ans << "(a_count: " << a_count << ")" << endl;
            ans += a_count;
            // Aを指している
            i += 2;
        }
        else if (s[i] == 'A' && s[i+1] == 'A') {
            a_count++;
            i++;
        }
        else {
            a_count = 0;
            i++;
        }
    }
    cout << ans << endl;
}
