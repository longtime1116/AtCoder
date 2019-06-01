#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n;
    cin >> n;
    lli a[n*3];
    REP(i, 0, 3*n) {
        cin >> a[i];
    }

    lli ans = -LLONG_MAX;
    REP(i, 0, n+1) {
        // 左から i 個、右から n-i 個取る
        lli l_count = n+i;
        //lli r_count = n+n-i;
        // l_count 入った que と r_count 入った que を作成
        priority_queue<lli, vector<lli>, greater<lli>> l_que;
        priority_queue<lli> r_que;
        lli l_sum = 0;
        lli r_sum = 0;
        REP(j, 0, 3*n) {
            if (j < l_count) {
                l_que.push(a[j]);
                l_sum += a[j];
            }
            else {
                r_que.push(a[j]);
                r_sum += a[j];
            }
        }
        REP(j, 0, n) {
            if (j < i) {
                l_sum -= l_que.top();
                l_que.pop();
            }
            else {
                r_sum -= r_que.top();
                r_que.pop();
            }
        }

        ans = max(ans, l_sum - r_sum);
    }
    cout << ans << endl;
}
