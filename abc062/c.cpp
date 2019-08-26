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


lli yoko(lli h, lli w) {
    if (h <= 2 && w <= 2)
        return LLONG_MAX;
    if (h % 3 == 0) {
        return 0;
    }
    else {
        return w;
    }
}

lli yokotate(lli h, lli w) {
    // ha は h / 3 か h / 3 + 1 のいずれか
    // wb/wc は w / 2 か w / 2 + 1 のいずれか
    lli ret = LLONG_MAX;
    REPE(ha, h/3, h/3+1) {
        REPE(wb, w/2, w/2+1) {
            // h が 2 のケースをケア
            if (ha == 0)
                continue;

            lli hb, hc;
            lli wa, wc;
            hb = hc =  h - ha;
            wa = w;
            wc = w - wb;

            lli max_area = max({wa * ha, wb * hb, wc * hc});
            lli min_area = min({wa * ha, wb * hb, wc * hc});
            ret = min(ret, max_area - min_area);
        }
    }
    return ret;
}

int main() {
    lli h, w;
    cin2(h, w);

    lli ans1 = LLONG_MAX;
    lli ans2 = LLONG_MAX;
    lli ans3 = LLONG_MAX;
    lli ans4 = LLONG_MAX;


    // 横斬り
    ans1 = yoko(h, w);
    // 縦横斬り、横先
    ans2 = yokotate(h, w);
    // 縦斬り
    ans3 = yoko(w, h);
    // 縦横斬り、縦先
    ans4 = yokotate(w, h);

    //cout1(ans1);
    //cout1(ans2);
    //cout1(ans3);
    //cout1(ans4);
    cout << min({ans1, ans2, ans3, ans4}) << endl;
}
