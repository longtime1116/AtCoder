#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,from, to) for(lli i=from;i<to;i++)
#define REPE(i,from, to) for(lli i=from;i<=to;i++)
#define REP_R(i,from, to) for(lli i=from;i>to;i--)
#define REPE_R(i,from, to) for(lli i=from;i>=to;i--)
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
#define cout2(x, y)      cout << #x << ": " << x << ", " << #y << ": " << y << endl;
#define cout3(x, y, z)   cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl;;
#define ncout1(n, x)     REP(i, 0, n) {cout << #x << "[" << i << "]: "<< x[i] << endl;}

#define coutp(p)         cout << #p << ":" <<  " (" << p.first << ", " << p.second << ")" << endl;

// sort
#define sort_r(x, y)        sort(x, y, greater<lli>()); // 降順(5,4,3,,,)

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;
typedef tuple<lli, lli, lli> tup;
typedef vector<lli> vlli;


// これはabc105のd問題ではないが、なぜか存在している。これはなんの問題なのだろうか？
int main() {
    lli h,w;
    cin2(h,w);
    lli a[h][w];
    REP(i,0,h) {
        REP(j,0,w) {
            cin >> a[i][j];
        }
    }

    vector<string> ans;
    REP(i,0,h) {
        REP(j,0,w) {
            lli cur;
            if (i % 2 == 0) {
                cur = j;

                if (a[i][cur] % 2 == 1) {
                    // 右か下に移す
                    if (cur != w-1) {
                        a[i][cur+1]++;
                        ans.push_back(to_string(i+1)+" "+to_string(cur+1)+" "+to_string(i+1)+" "+to_string(cur+2));

                    }
                    else if (i != h-1) {
                        ans.push_back(to_string(i+1)+" "+to_string(cur+1)+" "+to_string(i+2)+" "+to_string(cur+1));
                        a[i+1][cur]++;
                    }
                }
            }
            else {
                cur = (w-1)-j;
                if (a[i][cur] % 2 == 1) {
                    // 左か下に移す
                    if (cur != 0) {
                        ans.push_back(to_string(i+1)+" "+to_string(cur+1)+" "+to_string(i+1)+" "+to_string(cur));
                        a[i][cur-1]++;
                    }
                    else if (i != h-1) {
                        ans.push_back(to_string(i+1)+" "+to_string(cur+1)+" "+to_string(i+2)+" "+to_string(cur+1));
                        a[i+1][cur]++;
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
    REP(i,0,ans.size()) {
        cout << ans[i] << endl;
    }
}
