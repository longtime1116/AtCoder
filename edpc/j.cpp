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



lli n;
double E[301][301][301];

double rec(lli n_1, lli n_2, lli n_3) {
    if (n_1 == 0 && n_2 == 0 && n_3 == 0)
        return 0;
    if (E[n_1][n_2][n_3] != 0)
        return E[n_1][n_2][n_3];
    double e1, e2, e3;
    e1 = e2 = e3 = 0;
    if (n_1 > 0)
        e1 = rec(n_1-1, n_2, n_3) * n_1/(n_1+n_2+n_3);
    if (n_2 > 0)
        e2 = rec(n_1+1, n_2-1, n_3) * n_2/(n_1+n_2+n_3);
    if (n_3 > 0)
        e3 = rec(n_1, n_2+1, n_3-1) * n_3/(n_1+n_2+n_3);

    E[n_1][n_2][n_3] = e1+e2+e3+(n/(double)(n_1+n_2+n_3));
    //cout3(n_1,n_2,n_3);
    //cout1(E[n_1][n_2][n_3]);
    return E[n_1][n_2][n_3];
}

int main() {
    cin1(n);
    lli n_1, n_2, n_3;
    n_1 = n_2 = n_3 = 0;
    REP(i,0,n) {
        lli a;
        cin >> a;
        if (a == 1)
            n_1++;
        else if (a==2)
            n_2++;
        else
            n_3++;
    }

    cout <<std::setprecision(10)<< rec(n_1, n_2, n_3) << endl;
}
