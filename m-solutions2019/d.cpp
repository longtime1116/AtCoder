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
    lli a[n], b[n];
    priority_queue<lli> que;
    REP(i, 1, n) {
        cin >> a[i] >> b[i];
    }
    REP(i, 0, n) {
        lli c;
        cin >> c;
        que.push(c);
    }
    lli points[n+1] = {0};
    points[a[1]] = que.top();
    que.pop();
    points[b[1]] = que.top();
    que.pop();
    REP(i, 2, n) {
        REP(j, 2, n) {
            if (points[a[j]] == 0 && points[b[j]] != 0) {
                points[a[j]] = que.top();
                que.pop();
            }
            else if (points[a[j]] != 0 && points[b[j]] == 0) {
                points[b[j]] = que.top();
                que.pop();
            }
        }
    }
    lli ans = 0;
    REP(i, 1, n) {
        ans += min(points[a[i]], points[b[i]]);
    }
    cout << ans << endl;
    REPE(i, 1, n) {
        cout << points[i] << " ";
    }
    cout << endl;

    //map<lli, lli> m;
    //REP(i, 1, n) {
    //    auto it = m.find(a[i]);
    //    if (it != m.end()) {
    //        it->second += 1;
    //    }
    //    else {
    //        m.insert(make_pair(a[i], 1));
    //    }
    //    it = m.find(b[i]);
    //    if (it != m.end()) {
    //        it->second += 1;
    //    }
    //    else {
    //        m.insert(make_pair(b[i], 1));
    //    }
    //}
    //vector<P> v;
    //REPIT(it, m) {
    //    //printf("key: %d, value: %d\n", it->first, it->second);
    //    v.push_back(make_pair(it->second, it->first));
    //}
    //sort(v.begin(), v.end());
    ////REP(i, 0, v.size()) {
    ////    cout << v[i].first << ", " << v[i].second << endl;
    ////}

    //lli points[n+1];
    //REP(i, 0, v.size()) {
    //    // v[i].first は小さい順になっている。
    //    // v[i].second の位置に、小さい順に値を入れていく
    //    if (v[i].first == 0)
    //        continue;
    //    points[v[i].second] = que.top();
    //    que.pop();
    //}
    //// つながりをもたないところにはでかいものをいれたいので
    //REP(i, 0, v.size()) {
    //    if (v[i].first != 0)
    //        continue;
    //    points[v[i].second] = que.top();
    //    que.pop();
    //}
    //lli ans = 0;
    //REP(i, 1, n) {
    //    ans += min(points[a[i]], points[b[i]]);
    //}
    //cout << ans << endl;
    //REPE(i, 1, n) {
    //    cout << points[i] << endl;
    //}

}
