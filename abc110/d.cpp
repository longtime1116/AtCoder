#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

lli comb_table[100050][32];

void cal() {
    for (int i = 0; i < 100050; i++)
        comb_table[i][0] = 1;

    for (int j = 0; j < 32; j++)
        comb_table[j][j] = 1;


    for (int i = 2; i < 100050; ++i) {
        for (int j = 1; j < 32 and j < i; ++j) {
            comb_table[i][j] = ( comb_table[ i-1 ][j] + comb_table[ i-1 ][ j-1 ] ) % 1000000007;
        }
    }
    return;
}

lli comb(lli a, lli b) {
    lli p = a + b;
    lli q = min(a, b);

    // pCq を返す。
    cout <<"q: " <<  q << endl;
    vector <vector<lli> > v(p+1,vector<lli>(p+1,0));


    for(lli i = 0;i <v.size(); i++){
        v[i][0]=1;
        v[i][i]=1;
    }
    for(lli k = 1;k <v.size();k++){
        for(lli j = 1;j<32;j++){
            v[k][j]=(v[k-1][j-1]+v[k-1][j]);
        }
    }

    return v[p][q] % 1000000007;
}

int main() {
    lli n, m;
    cin >> n >> m;

    // 素因数 key が value 個ある、を表す map
    map<lli, lli> fac;
    lli num = m;
    for(lli i = 2; i*i<=num; i++) {
        while (num % i == 0) {
            fac[i]++;
            num /= i;
        }
    }
    if (num != 1)
        fac[num] = 1;


    cal();
    lli ans = 1;
    for(auto it = fac.begin(); it != fac.end(); it++) {
        //cout << it->first << " " << it->second << endl;

        // combination を計算
        ans = (ans * comb_table[n-1+it->second][it->second]) % 1000000007;
    }

    cout << ans << endl;

}
