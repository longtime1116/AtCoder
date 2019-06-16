#include <bits/stdc++.h>
using namespace std;

#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

bool is_done[51];

lli gcd(lli a, lli b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    lli r;
      r = a % b;

  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main() {
    lli n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<P> xy;
    REP(i, 0, n) {
        lli xi, yi;
        cin >> xi >> yi;
        xy.push_back(P(xi, yi));
    }
    sort(xy.begin(), xy.end());
    //REP(i, 0, xy.size()) {
    //    cout << "x: " << xy[i].first << ", y: " << xy[i].second << endl;
    //}
    lli ans = LLONG_MAX;
    REP(i, 0, n) {
        REP(j, 0, n) {
            if (i == j)
                continue;

            // この(p, q)の組み合わせでのコストを出す。
            lli p = xy[j].first - xy[i].first;
            lli q = xy[j].second - xy[i].second;

            // 集合を作る
            set<P> s;
            REP(i, 0, n) {
                s.insert(P(xy[i].first, xy[i].second));
            }

            // 一個取り出す => それに (p, q) を足してあったら消す、みたいにやっていく
            lli cur_cost = 0;
            REP(i, 0, n) {
                lli x = xy[i].first;
                lli y = xy[i].second;
                P orig = P(x, y);
                if (s.find(orig) == s.end()) {
                    continue;
                }
                s.erase(orig);
                cur_cost++;
                while (true) {
                    x += p;
                    y += q;
                    P target = P(x, y);

                    if (s.find(target) == s.end()) {
                        break;
                    }

                    s.erase(target);
                }
            }

            ans = min(ans, cur_cost);
        }
    }
    cout << ans << endl;
}
