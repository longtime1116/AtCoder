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

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

int main() {
    lli n;
    cin1(n);
    lli a[n*3];
    ncin1(n*3, a);

    priority_queue<lli, vector<lli>, greater<lli>> l_que;
    priority_queue<lli> r_que;
    REP(i, 0, n) {
        l_que.push(a[i]);
        r_que.push(a[n*3-1-i]);
    }

    lli l_target = n;
    lli r_target = n*2-1;
    REP(i, 0, (n+1)/2) {
        if (l_target == r_target) {
            // n が奇数でかつ最後のループの時のみここに入る
            lli l = l_que.top();
            lli r = r_que.top();
            if (a[l_target] - l > r - a[l_target]) {
                l_que.pop();
                l_que.push(a[l_target]);
            }
            else {
                r_que.pop();
                r_que.push(a[r_target]);
            }
        }
        else {
            // l_que から取り出したやつと、a[l_index] を比べて、入れ替え
            lli l = l_que.top();
            if (l < a[l_target]) {
                l_que.pop();
                l_que.push(a[l_target]);
                //cout << "l_que pushed: " << a[l_target] << endl;
            }
            l_target++;
            // r_que から取り出したやつと、a[r_index] を比べて、入れ替え
            lli r = r_que.top();
            if (r > a[r_target]) {
                r_que.pop();
                r_que.push(a[r_target]);
                //cout << "r_que pushed: " << a[r_target] << endl;
            }
            r_target--;
        }
    }
    // l_que から全部取り出して足したやつ - r_que から全部取り出して足したやつ
    lli ans = 0;
    while (!l_que.empty()) {
        ans = ans +  l_que.top() - r_que.top();
        //cout << "l_que poped: " << l_que.top() << endl;
        //cout << "r_que poped: " << r_que.top() << endl;
        l_que.pop();
        r_que.pop();
    }
    cout << ans << endl;
}
