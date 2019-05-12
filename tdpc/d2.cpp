#include <bits/stdc++.h>
using namespace std;

#define REP(i,begin, n) for(int i=begin;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

map<lli, lli> fac;

// dp[i][j][k][l]: i個目のサイコロを振った時点で2,3,5がそれぞれj,k,l個使われている確率
double dp[2][201][101][101];

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
    int cur = 0;
    int next = 1;
    REP(i, 0, n) {
        REP(j, 0, n*2-1) {
            if (j > 2 * n )
                break;
            REP(k, 0, n) {
                if (j+k > 2*n)
                    break;
                REP(l, 0, n) {
                    if (j+k+l > 2*n)
                        break;
                    // 1
                    dp[next][j][k][l] += dp[cur][j][k][l] * 1 / 6.0;

                    // 2
                    dp[next][j+1][k][l] += dp[cur][j][k][l] * 1 / 6.0;

                    // 3
                    dp[next][j][k+1][l] += dp[cur][j][k][l] * 1 / 6.0;

                    // 4
                    dp[next][j+2][k][l] += dp[cur][j][k][l] * 1 / 6.0;

                    // 5
                    dp[next][j][k][l+1] += dp[cur][j][k][l] * 1 / 6.0;

                    // 6
                    dp[next][j+1][k+1][l] += dp[cur][j][k][l] * 1 / 6.0;
                    dp[cur][j][k][l] = 0;
                }
            }
        }

        swap(cur, next);
    }

    double ans = 0;
    REP(j, fac[2], 201) {
        REP(k, fac[3], 101) {
            REP(l, fac[5], 101) {
                ans += dp[cur][j][k][l];
            }
        }
    }
    cout << ans << endl;
}
