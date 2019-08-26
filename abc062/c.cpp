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
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli h, w;
    cin2(h, w);

    lli ans1 = LLONG_MAX;
    lli ans2 = LLONG_MAX;
    lli ans3 = LLONG_MAX;
    lli ans4 = LLONG_MAX;
    // 横斬り

    if (h > 2) {
        if (h % 3 == 2) {
            lli x = (h + 1) / 3;
            lli y = (h - x) / 2;
            ans1 = (x - y) * w;
        }
        else {
            lli x = h / 3;
            lli y = h - x*2;
            ans1 = (y - x) * w;

        }
    }

    // 縦斬り
    if (w > 2) {
        if (w % 3 == 2) {
            lli x = (w + 1) / 3;
            lli y = (w - x) / 2;
            ans2 = (x - y) * h;
        }
        else {
            lli x = w / 3;
            lli y = w - x*2;
            ans2 = (y - x) * h;

        }
    }

    // 縦横斬り、横先
    lli xh = h / 3;
    lli yw = w / 2;
    REPE(i, xh, xh+1) {
        lli a = i * w;
        REPE(j, yw, yw+1) {
            if (i == 0 || j == 0)
                continue;
            lli b = j * (h-i);
            lli c = (w-j) * (h-i);
            lli min_men = min({a, b, c});
            lli max_men = max({a, b, c});
            ans3 = min(ans3, max_men - min_men);
            //cout1(a);
            //cout1(b);
            //cout1(c);
            //cout1(max_men);
            //cout1(min_men);
            //cout1(ans3);
        }
    }


    // 縦横斬り、縦先
    lli xw = w / 3;
    lli yh = h / 2;
    REPE(i, xw, xw+1) {
        lli a = i * h;
        REPE(j, yh, yh+1) {
            if (i == 0 || j == 0)
                continue;
            lli b = j * (w-i);
            lli c = (h-j) * (w-i);
            lli min_men = min({a, b, c});
            lli max_men = max({a, b, c});
            ans4 = min(ans4, max_men - min_men);
            //cout1(a);
            //cout1(b);
            //cout1(c);
            //cout1(max_men);
            //cout1(min_men);
            //cout1(ans3);
        }
    }
    //cout1(ans1);
    //cout1(ans2);
    //cout1(ans3);
    //cout1(ans4);
    cout << min({ans1, ans2, ans3, ans4}) << endl;
}
