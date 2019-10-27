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

int main() {
    string s;
    lli k;
    cin2(s,k);
    lli len = s.length();
    char str[len];
    char sorted_str[len];
    REP(i,0,len) {
        str[i] = s[i];
        sorted_str[i] = s[i];
    }
    sort(sorted_str, sorted_str+len);
    char cur_char = '.';
    set<string> ans;
    REP(i,0,len) {
        if (cur_char == sorted_str[i])
            continue;

        cur_char = sorted_str[i];
        // cur_char の場所のvectorを作る
        // どれが一番いいかを見て、あればそれで終わり
        REP(j,0,len) {
            if (str[j] != cur_char)
                continue;

            // [j, j+k-1] を得る
            REPE(l,1,k) {
                if (j+l-2>=len)
                    continue;
                if (ans.find(s.substr(j, l)) == ans.end()) {
                    ans.insert(s.substr(j, l));
                    //cout1(s.substr(j, l));
                }
            }
        }
        //cout1(ans.size());
        if (ans.size() >= k)
            break;
    }
    auto it = ans.begin();
    REP(i,1,k) {
        it++;
    }
    cout << *it << endl;
}
