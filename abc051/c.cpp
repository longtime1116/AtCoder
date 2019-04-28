#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int sx, sy, tx, ty;
    string ans = "";
    cin >> sx >> sy >> tx >> ty;
    // 1週目
    REP(i, tx-sx) {
        ans += "R";
    }
    REP(i, ty-sy) {
        ans += "U";
    }
    REP(i, tx-sx) {
        ans += "L";
    }
    REP(i, ty-sy) {
        ans += "D";
    }
    // 2週目
    ans += "D";
    REP(i, tx-sx+1) {
        ans += "R";
    }
    REP(i, ty-sy+1) {
        ans += "U";
    }
    ans += "L";
    ans += "U";
    REP(i, tx-sx+1) {
        ans += "L";
    }
    REP(i, ty-sy+1) {
        ans += "D";
    }
    ans += "R";
    cout << ans << endl;
}
