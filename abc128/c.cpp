#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int k[11];
int s[11][11]; // s[i][j]
int p[11];
bool sw[11];
int n, m;

bool all_ok() {
    REPE(i, 1, m) {
        int on_count = 0;
        REPE(j, 1, k[i]) {
            if (sw[s[i][j]])
                on_count++;
        }
        if ((on_count % 2) != p[i])
            return false;
    }
    return true;
}

lli rec(int done_count) {
    // 最後まで行ったら判定
    if (done_count == n) {
        if (all_ok())
            return 1;
        else
            return 0;
    }
    lli ans = 0;
    int ind = done_count+1;

    // スイッチ use_index を on にする
    sw[ind] = true;
    ans += rec(ind);

    // スイッチ use_index を off にする
    sw[ind] = false;
    ans += rec(ind);

    return ans;
}

int main() {
    cin >> n >> m;
    REPE(i, 1, m) {
        cin >> k[i];
        REPE(j, 1, k[i]) {
            cin >> s[i][j];
        }
    }
    REPE(i, 1, m) {
        cin >> p[i];
    }


    lli ans = 0;
    ans = rec(0);
    cout << ans << endl;
}
