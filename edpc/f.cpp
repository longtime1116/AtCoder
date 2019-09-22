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


// dp[i][j] := sのi文字目までとtのj文字目までの状態での最長部分列長
lli dp[3001][3001];

int main() {
    string s, t;
    cin2(s, t);
    lli slen = s.length();
    lli tlen = t.length();

    s = "#" + s;
    t = "." + t;
    REPE(i,1,slen) {
        REPE(j,1,tlen) {
            if (s[i] == t[j]) {
                //dp[i][j] = max(dp[i-1][j-1], dp[i][j-1]) + 1;
                dp[i][j] = dp[i-1][j-1] + 1;
                //cout << "if" << endl;
                //cout2(i,j);
                //cout1(dp[i][j])
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                //dp[i][j] = dp[i][j-1];
                //dp[i][j] = dp[i-1][j-1];
                //cout << "else" << endl;
                //cout2(i,j);
                //cout1(dp[i][j])
            }
        }
    }
    //REPE(i,0,slen) {
    //    REPE(j,0,tlen) {
    //        cout<<dp[i][j];
    //    }
    //    cout << endl;
    //}
    //cout << dp[slen][tlen] << endl;

    vector<lli> ans;
    lli j_cur = tlen;
    REP_R(i,slen, 0) {
        lli cur = dp[i][j_cur];
        if (cur == 0)
            break;
        if (cur == dp[i-1][j_cur])
            continue;
        REP_R(j,j_cur,0) {
            if (s[i] == t[j]) {
                ans.push_back(j);
                j_cur = j-1;
                break;
            }
        }
        if (j_cur == 0)
            break;
    }
    REP(i,0,ans.size()) {
        cout << t[ans[ans.size()-1-i]];
    }
    cout<<endl;
}

// axyb
// abyxb
//000000
//011111
//011122
//011222
//012223

// abracadabra
// avadakedavra
//0000000000000
//0111111111111
//0111111111111
//0111111111122
//0112222222223
//0112222222223
//0112233333333
//0112333344444
//0112344445555
//0112344445555
//0112344445566
//0112344445567


//aaabcaaa
//bbaaacaaabcaa
//00000000000000
//00011111111111
//00012222222222
//00012333333333
//01112333334444
//01112344444555
//01122345555566
//01123345666667
//01123445677777
