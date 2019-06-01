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

    priority_queue<lli, vector<lli>, greater<lli>> l_que;
    lli l_sum = 0;
    REP(i, 0, n) {
        l_que.push(a[i]);
        l_sum += a[i];
    }
    lli l_sums[n+1];
    l_sums[0] = l_sum;
    REP(i, 1, n+1) {
        // 左から i 個、右から n-i 個取る
        // n+i 個目を入れて何かを捨てる
        l_sum += a[n+i-1];
        l_que.push(a[n+i-1]);
        l_sum -= l_que.top();
        l_que.pop();

        l_sums[i] = l_sum;
    }

    priority_queue<lli> r_que;
    lli r_sum = 0;
    REP(i, 0, n) {
        r_que.push(a[3*n-i-1]);
        r_sum += a[3*n-i-1];
    }
    lli r_sums[n+1];
    r_sums[n] = r_sum;
    REP(i, 1, n+1) {
        // 右から i 個、左から n-i 個取る
        // 2*n-i 個目を入れて何かを捨てる
        r_sum += a[2*n-i];
        r_que.push(a[2*n-i]);
        r_sum -= r_que.top();
        r_que.pop();

        r_sums[n-i] = r_sum;
    }
    lli ans = -LLONG_MAX;
    REP(i, 0, n+1) {
        ans = max(ans, l_sums[i] - r_sums[i]);
    }
    cout << ans << endl;
    //lli ans = -LLONG_MAX;
    //REP(i, 0, n+1) {
    //    // 左から i 個、右から n-i 個取る
    //    lli l_count = n+i;
    //    //lli r_count = n+n-i;
    //    // l_count 入った que と r_count 入った que を作成
    //    priority_queue<lli, vector<lli>, greater<lli>> l_que;
    //    priority_queue<lli> r_que;
    //    lli l_sum = 0;
    //    lli r_sum = 0;
    //    REP(j, 0, 3*n) {
    //        if (j < l_count) {
    //            l_que.push(a[j]);
    //            l_sum += a[j];
    //        }
    //        else {
    //            r_que.push(a[j]);
    //            r_sum += a[j];
    //        }
    //    }
    //    REP(j, 0, n) {
    //        if (j < i) {
    //            l_sum -= l_que.top();
    //            l_que.pop();
    //        }
    //        else {
    //            r_sum -= r_que.top();
    //            r_que.pop();
    //        }
    //    }

    //    ans = max(ans, l_sum - r_sum);
    //}
    //cout << ans << endl;
}
