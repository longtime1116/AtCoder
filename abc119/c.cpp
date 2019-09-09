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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;

int main() {
    lli n;
    cin1(n);
    lli a,b,c;
    cin3(a,b,c);
    lli l[n];
    ncin1(n, l);
    lli ans = LLONG_MAX;
    // {i,j,k}: 配列 l を左から i個、j個、k個 それぞれ合成し、 A、B、C を作成
    // 配列 l は next_permutation ですべての組み合わせで調べる
    REPE(i, 1, n) {
        REPE(j, 1, n) {
            if (i + j > n)
                continue;
            REPE(k, 1, n) {
                if (i + j + k > n)
                    continue;
                sort(l, l+n);
                do {
                    lli total = 0;
                    lli sum = 0;
                    REP(p, 0, i) {
                        sum += l[p];
                        if (p != 0)
                            total += 10;
                    }
                    total += abs(sum - a);

                    sum = 0;
                    REP(p, i, i+j) {
                        sum += l[p];
                        if (p != i)
                            total += 10;
                    }
                    total += abs(sum - b);

                    sum = 0;
                    REP(p, i+j, i+j+k) {
                        sum += l[p];
                        if (p != i+j)
                            total += 10;
                    }
                    total += abs(sum - c);

                    //cout3(i,j,k);
                    //cout1(total);
                    //REP(i,0,n) {
                    //    cout << l[i] << ", ";
                    //}
                    //cout << endl;
                    ans = min(ans, total);

                } while (next_permutation(l, l+n));
            }
        }
    }
    cout << ans << endl;
}
