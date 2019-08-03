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

lli is_prime[100001]; // i 番目が素数かどうか
lli prime_count[100001]; // i 番目までに何個の素数が含まれているか

// n以下の自然数に何個素数が含まれるのかを返す
// sieve(10) => 4
lli sieve(lli n) {
    lli p = 0;
    REPE(i, 0, n) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    REPE(i, 2, n) {
        if (is_prime[i]) {
            p++;
            for (lli j = 2*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return p;
}

int main() {
    sieve(100000);
    lli q;
    cin1(q);
    lli l[q], r[q];
    ncin2(q, l, r);
    lli count = 0;
    REPE(i, 2, 100000) {
        if (i % 2 == 0) {
            prime_count[i] = count;
            continue;
        }
        if (is_prime[i] && is_prime[(i+1)/2])
            count++;
        prime_count[i] = count;
    }

    REP(i, 0, q) {
        cout << prime_count[r[i]] - prime_count[l[i]-1] << endl;
    }

}
