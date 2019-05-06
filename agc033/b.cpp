#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int sr, sc;
    cin >> sr >> sc;
    string s, t;
    cin >> s >> t;

    int s_l, s_r, s_u, s_d;
    s_l = count(s.cbegin(), s.cend(), 'L');
    s_r = count(s.cbegin(), s.cend(), 'R');
    s_u = count(s.cbegin(), s.cend(), 'U');
    s_d = count(s.cbegin(), s.cend(), 'D');


    // left_l 個まではいける。
    int left_l, left_r, left_u, left_d;
    left_l = sr - 1;
    left_r = w - sr;
    left_u = sc - 1;
    left_d = h - sc;

    bool l_p, r_p, u_p, d_p;
    l_p = r_p = u_p = d_p = false;
    if (left_l - s_l < 0)
        l_p = true;
    if (left_r - s_r < 0)
        r_p = true;
    if (left_u - s_u < 0)
        u_p = true;
    if (left_u - s_d < 0)
        d_p = true;

    int safe_l = 1;
    int safe_r = w;
    for(int i=n-1; i>=0; i--) {
        if (s[i] == 'R')
            safe_r--;
        else if (s[i] == 'L')
            safe_l++;

        if (safe_r < safe_l) {
            cout << "NO" << endl;
            return 0;
        }
        if (i != 0) {
            if (t[i-1] == 'L' && safe_r < w)
                safe_r++;
            else if (t[i-1] == 'R' && safe_l > 1)
                safe_l--;
        }
    }
    if (sc < safe_l || sc > safe_r) {
        cout << "NO" << endl;
        return 0;
    }
    int safe_u = 1;
    int safe_d = h;
    for(int i=n-1; i>=0; i--) {
        if (s[i] == 'D')
            safe_d--;
        else if (s[i] == 'U')
            safe_u++;
        if (safe_d < safe_u) {
            cout << "NO" << endl;
            return 0;
        }
        if (i != 0) {
            if (t[i-1] == 'U' && safe_d < h)
                safe_d++;
            else if (t[i-1] == 'D' && safe_u > 1)
                safe_u--;
        }
    }
    if (sr < safe_u || sr > safe_d) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}
