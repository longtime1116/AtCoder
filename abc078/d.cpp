#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
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
typedef vector<lli> vlli;



// 考察
//
// a1 a2 ... ai ...  aj ... an-1 an
//
// 初手で終わらせる場合の解は、
//  max(|an-1 - an|, |an-1 - w|)
// x が aiを取ったとし、その後 y が aj を取ったとする
// x の次の一手は、n-1/n 以外を取った場合は↑に戻る。n-1/nを取った時は、
// max(|an-1 - an|, |an-1 - aj|)
// ここで、|an-1 - aj| が |an-1 - w| より大きくなるような aj を y がとるはずがない
// よって、x が ai を取った場合のスコアは高々 |an-1 - an| となる。
// なので、初手で終わらせる方が w によっては特になる場合は初手で終わらせるべきだし、そうでない場合も結局は初手で終わらせた場合と同じ結果になる
int main() {
    lli n,z,w;
    cin3(n,z,w);
    lli a[n+1];
    ncin1(n,a);

    if (n == 1)
        cout << abs(a[0] - w) << endl;
    else
        cout << max(abs(a[n-2] - a[n-1]), abs(a[n-1] - w)) << endl;

}
