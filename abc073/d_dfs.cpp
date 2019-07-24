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

lli dp[301][301]; // k 個分用意しなくても上書きしてけば良いので、dp[i][j]のみ用意
#define INF (LLONG_MAX / 3);

bool used[9];
lli r[9];
lli N, M, R;

lli rec(lli cur, lli used_count) {
    if (used_count == R) {
        return 0;
    }

    // r[i] が未使用ならそれを使う
    lli ans = LLONG_MAX;
    REPE(i, 1, R) {
        lli target = r[i];
        if (target == cur || used[target])
            continue;

        used[cur] = true;
        ans = min(ans, rec(target, used_count+1) +dp[cur][target]);
        //cout1(target);
        //cout1(used_count);
        //cout1(ans);
        used[cur] = false;
    }
    return ans;
}

int main() {
    cin3(N, M, R);
    REPE(i, 1, R) {
        cin >> r[i];
    }
    REP(i, 0, M) {
        lli from, to, cost;
        cin >> from >> to >> cost;
        dp[from][to] = dp[to][from] = cost;
    }

    // 初期化
    REPE(i, 1, N) {
        REPE(j, 1, N) {
            if (dp[i][j])
                continue;
            if (i == j)
                continue;
            dp[i][j] = INF;
        }
    }

    REPE(k, 1, N) {
        REPE(i, 1, N) {
            REPE(j, 1, N) {
                dp[j][i] = dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    lli ans = LLONG_MAX;
    REPE(i, 1, R) {
        used[r[i]] = true;
        ans = min(ans, rec(r[i], 1));
        used[r[i]] = false;
    }
    cout << ans << endl;
    // dump
    //cout << endl;
    //REPE(i, 1, N) {
    //    REPE(j, 1, N) {
    //        cout << i << "-" << j << ": " << dp[i][j] << endl;
    //    }
    //    cout << endl;
    //}

    // Rの順番を全て舐める

}



