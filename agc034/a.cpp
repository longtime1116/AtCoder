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
    lli n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    lli len = s.length();

    // X がいけるかどうかチェック
    // c<d なら、Yがdについてしまってからいけばいい
    if (c < d) {
        // まず Y がいってしまうべき => 行けなかったら終わり
        REP(i, b-1, d-1) {
            if (s[i] == '#' && s[i+1] == '#') {
                cout << "No" << endl;
                return 0;
            }
        }
        // 次に X がいく
        REP(i, a-1, c-1) {
            if (s[i] == '#' && s[i+1] == '#') {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    // まず そもそもY がいけるか？
    REP(i, b-1, d-1) {
        if (s[i] == '#' && s[i+1] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }
    // A がまたぐ余地があるか？
    REP(i, b-1, d) {
        if (s[i] == '#')
            continue;
        if (s[i-1] == '.' && s[i+1] == '.') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
