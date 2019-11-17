#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(unsigned long long int i=from;i<to;i++)
#define REPE(i,from, to) for(unsigned long long int i=from;i<=to;i++)
#define REP_R(i,from, to) for(unsigned long long int i=from;i>to;i--)
#define REPE_R(i,from, to) for(unsigned long long int i=from;i>=to;i--)
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
#define sort_r(x, y)        sort(x, y, greater<unsigned long long int>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef pair<unsigned long long int, unsigned long long int> P;
typedef tuple<unsigned long long int, unsigned long long int, unsigned long long int> tup;
typedef vector<unsigned long long int> vlli;


unsigned long long int mod = 1000000007;
unsigned long long int mul(unsigned long long int x, unsigned long long int y) {
    return (x * y) % mod;
}

int main() {
    unsigned long long int x,y;
    cin2(x,y);
    // x <= y とする
    if (x > y) {
        unsigned long long int tmp = x;
        x = y;
        y = tmp;
    }
    unsigned long long int set_count = x / 3;
    unsigned long long int x_rest = x - set_count * 3;
    unsigned long long int y_rest = y - set_count * 3;
    if (x_rest * 2 != y_rest) {
        cout << 0 << endl;
        return 0;
    }
    //cout << "hoge" << endl;
    // set_count 分の可能性にかける
    unsigned long long int ans = x_rest + 1;

    cout1(ans);

    unsigned long long int left;
    unsigned long long int right;
    unsigned long long int hoge = 1;
    REPE(i,1,set_count) {
        left = i*2;
        right = i;

        //hoge = mul(hoge, left);
        //hoge = mul(hoge, left-1);
        //hoge /= right;
        //hoge /= right;
        hoge /= right;
        hoge = mul(hoge, 2);
        hoge = mul(hoge, left-1);

        cout1(hoge);
    }
    cout << mul(hoge, ans) << endl;

}
