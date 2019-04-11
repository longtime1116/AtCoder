#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define MP          make_pair

#define REP(i, n)   for(int i = 0; i < n; i++)

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef long long ll;

// FIXME : nCr の値がオーバーフローする
// 例 981 159373724 -637494896 -159373724



int     N;
ll      D, X, Y;

ll comb(
    int     n,
    int     r)
{
    // nCr を返す。
    ll     tpas[n+1];
    ll     tmp[n+1];

    memset(tpas, 0, sizeof(tpas));
    memset(tmp, 0, sizeof(tmp));

    REP(i, n+1) {
        REP(j, i+1) {
            if ( j == 0 )
                tmp[j] = 1;
            else
                tmp[j] = tpas[j-1] + tpas[j];
        }
        REP(j, i+1) {
            tpas[j] = tmp[j];
        }
    }
    return tpas[r];
}

int main (void)
{
    ll pattern = 0;
    double  ans = 0;
    cin >> N >> D >> X >> Y;

    cout << N << " ";
    cout << D << " ";
    cout << X << " ";
    cout << Y << endl;
    if ( X % D == 0 && Y % D == 0 ) {
        X /= D;
        Y /= D;
    cout << "X :" << X << endl;
    cout << "Y : " << Y << endl;
    }
    else {
        printf("%8f\n", 0.0);
        return 0;
    }
    if ( abs(X + Y) % 2 != (N%2) ) {
        printf("%8f\n", 0.0);
        return 0;
    }
    X = abs(X);
    Y = abs(Y);
    for ( int i = X; i <= N - Y; i +=2  ) {
        int r = (i + X) / 2;
        int l = i - r;
        int u = (N - i + Y) / 2;
        int d = N - i - u;
        cout << "hoge" << endl;
        cout << "r : "<< r << endl << "l : "<< l << endl <<  "u : "<< u << endl <<"d : "<<d <<endl;
        cout << "comb(N, i) : "<< comb(N, i) << endl << "comb(r+l, r) : "<< comb(r+l, r) << endl <<  "comb(u+d, d) : "<< comb(u+d, d)  <<endl;
        ans += ( comb(N, i) * comb(r+l, r) * comb(u+d, u) ) / pow(4.0, N);
        cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
