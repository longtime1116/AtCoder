#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;


lli comb(lli p, lli a) {
    lli q = min(a, p-a);

    // pCq を返す。
    //cout <<"q: " <<  q << endl;
    vector <vector<lli> > v(p+1,vector<lli>(p+1,0));


    for(lli i = 0;i <v.size(); i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(lli k = 1;k <v.size();k++){
        for(lli j = 1;j<32;j++){
            v[k][j]=(v[k-1][j-1]+v[k-1][j]) % 1000000007;
        }
    }

    return v[p][q] % 1000000007;
}

lli comb_table[4002][4002];

void cal() {
    for (int i = 0; i < 4002; i++)
        comb_table[i][0] = 1;

    for (int j = 0; j < 4002; j++)
        comb_table[j][j] = 1;


    for (int i = 2; i < 4002; ++i) {
        for (int j = 1; j < 4002 and j < i; ++j) {
            comb_table[i][j] = ( comb_table[ i-1 ][j] + comb_table[ i-1 ][ j-1 ] ) % 1000000007;
        }
    }
    return;
}

int main() {
    lli n, k;
    cin >> n >> k;
    cal();
    REP(i, 0, k) {
        if (i == 0)
            cout << n - k + 1 << endl;
        else {
            // i: 1 のとき、k は2つ、すきまは2C1、残りは左右 => 2C1 * (n-(k+i)) + 1
            lli ans;
            lli a = comb_table[k-1][i];
            lli b = comb_table[(i+1+n-k-i)][n-k-i];
            ans = a * b % 1000000007;
            //cout << "a: " << a;
            //cout << ", b: " << b << endl;
            //ans = comb_table[k-1][i] * (i+k-1);
            //cout << "comb: " << comb_table[k-1][i];
            //cout << ", (n-(k+i) + 1): " << (i+k-1) << endl;
            cout << ans << endl;

        }

    }
}
