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

void z_algorithm(const string s, lli *z) {
    lli len = s.length();

    // 0文字目に何を入れたいかに依る
    z[0] = 0;

    lli left = 0;
    lli right = 0;
    REP(i, 1, len) {
        if (i > right) {
            left = right = i;
            while (true) {
                if (right >= len || s[right-left] != s[right])
                    break;
                right++;
            }
            z[i] = right - left;
            right--;
        }
        else {
            lli j = i - left;
            // z-box の範囲に収まっている場合はそのままz-boxの値を入れれば良い
            if (z[j] < right - i + 1) {
                z[i] = z[j];
            }
            else {
                left = i;
                while (true) {
                    if (right >= len || s[right-left] != s[right])
                        break;
                    right++;
                }
                z[i] = right - left;
                right--;
            }

        }

    }
}

int main() {
    lli n;
    string s;
    cin1(n);
    cin1(s);
    lli ans = 0;
    REP(i,0,n) {
        lli z[n-i];
        z_algorithm(s.substr(i), z);

        //cout << s.substr(i,n-i) << endl;
        REP(j,0,n-i) {
            ans = max(ans, min(z[j], j));
            //cout << z[j];
        }
        //cout << endl;
    }
    cout << ans << endl;
}
