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

struct RollingHash {
    static const int base = 1007;
    static const int mod = 1000000007;
    // another version
    //static const int base = 2009;
    //static const int mod = 1000000009;

    vector<lli> hash, power;

    RollingHash(const string &S) {
        lli n = S.size();
        hash.assign(n+1, 0);
        power.assign(n+1, 1);
        REP(i,0,n) {
            hash[i+1] = (hash[i] * base + S[i]) % mod;
            power[i+1] = (power[i] * base) % mod;
        }
    }

    // get hash value of S[left:right]
    lli get(lli l, lli r) {
        lli ret = hash[r] - hash[l] * power[r-l] % mod;
        if (ret < 0)
            ret += mod;
        return ret;
    }

    // get lcp of S[i:] and S[j:]
    lli get_lcp(lli i, lli j) {
        lli low = 0;
        lli high = hash.size() - max(i, j);

        while (high - low > 1) {
            lli mid = (low + high) / 2;
            if (get(i, i+mid) == get(j, j+mid)) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    lli n;
    string s;
    cin1(n);
    cin1(s);
    RollingHash rh(s);
    lli low = 0;
    lli high = n;
    lli ans = 0;
    while (high - low > 1) {
        lli mid = (high + low) / 2;
        bool update = false;
        REP(i,0,n) {
            REP(j,i+mid,n) {
                if (rh.get(i, i+mid) == rh.get(j, j+mid)) {
                    bool is_correct = true;
                    REP(k,0,mid) {
                        if (s[i+k] != s[j+k]) {
                            is_correct = false;
                            break;
                        }
                    }
                    if (!is_correct)
                        continue;
                    ans = max(ans, mid);
                    update = true;
                    goto NEXT;
                }
            }
        }
NEXT:
        if (update) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout << ans << endl;
}
