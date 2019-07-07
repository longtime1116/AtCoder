#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli dp[101][101]; // k 個分用意しなくても上書きしてけば良いので、dp[i][j]のみ用意
bool used[101][101];
lli edges[101][101];
#define INF (LLONG_MAX / 3);

int main() {
    lli n, m;
    cin >> n >> m;
    REP(i, 0, m) {
        lli from, to, cost;
        cin >> from >> to >> cost;
        dp[from][to] = dp[to][from] = cost;
        edges[from][to] = edges[to][from] = cost;
    }

    // 初期化
    REPE(i, 1, n) {
        REPE(j, 1, n) {
            if (dp[i][j])
                continue;
            if (i == j)
                continue;
            dp[i][j] = INF;
        }
    }

    // 最短経路作成
    REPE(k, 1, n) {
        REPE(i, 1, n) {
            REPE(j, 1, n) {
                dp[j][i] = dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    REPE(k, 1, n) {
        REPE(i, 1, n) {
            REPE(j, 1, n) {
                if (edges[i][j]) {
                    if (dp[i][j] == edges[i][j]) {
                        used[i][j] = used[j][i] = true;
                    }
                }
                if (edges[i][k]) {
                    if (dp[i][j] == edges[i][k] + dp[k][j]) {
                        used[i][k] = used[k][i] = true;
                    }

                }
                if (edges[k][j]) {
                    if (dp[i][j] == dp[i][k] + edges[k][j]) {
                        used[k][j] = used[j][k] = true;
                    }
                }
            }
        }
    }

    // dump
    lli ans = 0;
    REPE(i, 1, n) {
        REPE(j, i+1, n) {
            //cout << i << "-" << j << ": " << dp[i][j] << endl;
            if (!edges[i][j])
                continue;
            //cout << i << "-" << j << ": " << used[i][j] << endl;
            if (!used[i][j])
                ans++;
        }
    }
    cout << ans << endl;

}

// 4 5 1 2 1 1 3 3 2 3 2 2 4 1 3 4 100
// 5 5 1 2 12 2 3 14 3 4 7 4 5 9 5 1 18
