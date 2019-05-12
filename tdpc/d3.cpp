#include <bits/stdc++.h>
using namespace std;

#define REP(i,begin, n) for(int i=begin;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

map<lli, int> fac;

// dp[i][j][k][l]: i個目のサイコロを振った時点で2,3,5がそれぞれj,k,l個使われている確率
double dp[101][63][63][63];

int main() {
    int n;
    lli d;
    cin >> n >> d;

    while(d%2==0){
        d=d/2;
        fac[2]++;
    }
    while(d%3==0){
        d=d/3;
        fac[3]++;
    }
    while(d%5==0){
        d=d/5;
        fac[5]++;
    }
    if(d!=1){
        cout<<0<<endl;
        return 0;
    }

    dp[0][0][0][0] = 1.0;
    REP(i, 0, n) {
        REP(j, 0, fac[2]+1) {
            REP(k, 0, fac[3]+1) {
                REP(l, 0, fac[5]+1) {
                    // 1
                    dp[i+1][j][k][l] += dp[i][j][k][l] * 1 / 6.0;

                    // 2
                    dp[i+1][min(j+1, fac[2])][k][l] += dp[i][j][k][l] * 1 / 6.0;

                    // 3
                    dp[i+1][j][min(k+1, fac[3])][l] += dp[i][j][k][l] * 1 / 6.0;

                    // 4
                    dp[i+1][min(j+2, fac[2])][k][l] += dp[i][j][k][l] * 1 / 6.0;

                    // 5
                    dp[i+1][j][k][min(l+1, fac[5])] += dp[i][j][k][l] * 1 / 6.0;

                    // 6
                    dp[i+1][min(j+1, fac[2])][min(k+1, fac[3])][l] += dp[i][j][k][l] * 1 / 6.0;
                }
            }
        }
    }

    double ans = dp[n][fac[2]][fac[3]][fac[5]];
    cout << ans << endl;
}
