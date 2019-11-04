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
    cin1(s);
    //if (s[0] == '<')
    //    s = ">" + s;
    //if (s[s.length()-1] == '>')
    //    s = s + '<';

    // >< になっている間は0になる
    lli count = 0;
    lli gt_count = 0;
    lli lt_count = 0;
    lli ans = 0;
    REPE(i,0,s.length()-1) {
        if (s[i] == '>')
            lt_count++;
        else
            gt_count++;


        if (i == s.length()-1) {
            // last
            if (lt_count == 0) {
                ans += (1+gt_count) * gt_count / 2;
            }
            else {
                ans += (gt_count-1) * gt_count / 2;
                ans += (lt_count-1) * lt_count / 2;
                if (gt_count > lt_count)
                    ans += gt_count;
                else
                    ans += lt_count;
                //cout1((gt_count-1) * gt_count / 2);
                //cout1((lt_count-1) * lt_count / 2);
                //cout1(lt_count+1);
            }
            gt_count = lt_count = 0;
            count = 0;

        }
        else if (s[i] == '>' && s[i+1] == '<') {
            if (gt_count == 0) {
                ans += (1+lt_count) * lt_count / 2;
            }
            else {
                ans += (gt_count-1) * gt_count / 2;
                ans += (lt_count-1) * lt_count / 2;
                if (gt_count > lt_count)
                    ans += gt_count;
                else
                    ans += lt_count;
                //cout1((gt_count-1) * gt_count / 2);
                //cout1((lt_count-1) * lt_count / 2);
                //cout1(lt_count+1);
            }
            gt_count = lt_count = 0;
            count = 0;
            continue;
        }
        //if (s[i] == '>' && s[i+1] == '<') {
        //    // 精算する
        //    ans += (1+gt_count) * gt_count / 2;
        //    ans += (1+lt_count) * lt_count / 2;
        //    if (gt_count > lt_count)
        //        ans += gt_count+1;
        //    else
        //        ans += lt_count+1;


        //    gt_count = lt_count = 0;
        //    count = 0;
        //    continue;
        //}
        //else if (s[i] == '<' && s[i+1] == '<') {
        //    gt_count++;
        //}
        //else if (s[i] == '<' && s[i+1] == '>') {
        //    // gt_count + 1 続いた
        //    continue;
        //}
        //else if (s[i] == '>' && s[i+1] == '>') {
        //    lt_count++;
        //}
    }
    // 最後の処理

    cout << ans << endl;
}
