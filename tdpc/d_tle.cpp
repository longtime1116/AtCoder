#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

map<lli, lli> fac;

int dp[1000000000000000000][100];

bool is_resolved() {
    for(auto it = fac.begin(); it != fac.end(); it++) {
        if (it->second > 0)
            return false;
    }
    return true;
}

lli rec(lli num, int left_count) {
    if (is_resolved()) {
        //cout << "000" << endl;
        return pow(6, left_count);
    }
    if (left_count == 0) {
        //cout << "111" << endl;
        return 0;
    }

    lli result = 0;

    // 1 のとき
    result += rec(num, left_count-1);

    // 2 のとき
    if (num % 2 == 0) {
        fac[2] -= 1;
        result += rec(num/2, left_count-1);
        fac[2] += 1;
    }
    else {
        result += rec(num, left_count-1);
    }

    // 3 のとき
    if (num % 3 == 0) {
        fac[3] -= 1;
        result +=  rec(num/3, left_count-1);
        fac[3] += 1;
    }
    else {
        result +=  rec(num, left_count-1);
    }

    // 4 のとき
    if (num % 4 == 0) {
        fac[2] -= 2;
        result += rec(num/4, left_count-1);
        fac[2] += 2;
    }
    else if (num % 2 == 0){
        fac[2] -= 1;
        result += rec(num/2, left_count-1);
        fac[2] += 1;
    }
    else
        result +=  rec(num, left_count-1);

    // 5 のとき
    if (num % 5 == 0) {
        fac[5] -= 1;
        result += rec(num/5, left_count-1);
        fac[5] += 1;
    }
    else
        result +=  rec(num, left_count-1);

    // 6 のとき
    if (num % 6 == 0) {
        fac[2] -= 1;
        fac[3] -= 1;
        result += rec(num/6, left_count-1);
        fac[2] += 1;
        fac[3] += 1;
    }
    else if (num % 2 == 0){
        fac[2] -= 1;
        result += rec(num/2, left_count-1);
        fac[2] += 1;
    }
    else if (num % 3 == 0){
        fac[3] -= 1;
        result += rec(num/3, left_count-1);
        fac[3] += 1;
    }
    else
        result +=  rec(num, left_count-1);

    //result += rec(num, left_count-1);
    //for (int i = 1; i < 7; i++) {
    //    int q = num / i;
    //    int r = num % i;
    //    if (i == 1 || q == 0) {
    //        rec(num, left_count-1);
    //    }
    //    if (i == 2) {
    //        fac[2] -= 1;
    //        result += rec(q, left_count-1);
    //        fac[2] += 1;
    //    }
    //    if (i == 3) {
    //        fac[3] -= 1;
    //        result += rec(q, left_count-1);
    //        fac[3] += 1;
    //    }
    //    if (i == 4) {
    //        fac[2] -= 2;
    //        if ()
    //        result += rec(q, left_count-1);
    //        fac[2] += 2;
    //    }
    //    if (i == 5) {
    //        fac[5] -= 1;
    //        result += rec(q, left_count-1);
    //        fac[5] += 1;
    //    }
    //    if (i == 6) {
    //        fac[2] -= 1;
    //        fac[3] -= 1;
    //        result += rec(q, left_count-1);
    //        fac[2] += 1;
    //        fac[3] += 1;
    //    }
    //    //int q = num / i;
    //    //int r = num % i;
    //    //if (q > 0) {
    //    //    if ( r == 0 ) {
    //    //        cout << "aaa" << endl;
    //    //        cout << "q: " << q << ", left_count-1: " << left_count - 1 << endl;
    //    //        result += rec(q, left_count-1);
    //    //    }
    //    //    else {
    //    //        cout << "bbb" << endl;
    //    //        cout << "num: " << num << ", left_count-1: " << left_count - 1 << endl;
    //    //        result += rec(num, left_count-1);
    //    //    }
    //    //}
    //    //else {
    //    //    q = i / num;
    //    //    r = i % num;
    //    //    if (r == 0) {
    //    //        cout << "ccc" << endl;
    //    //        result += pow(6, left_count-1);
    //    //    }
    //    //    else
    //    //        cout << "ddd" << endl;

    //    //}
    //}
    return result;
}

int main() {
    int n;
    lli d;
    cin >> n >> d;
    // 素因数 key が value 個ある、を表す map
    lli num = d;
    for(lli i = 2; i*i<=num; i++) {
        while (num % i == 0) {
            fac[i]++;
           num /= i;
        }
    }
    if (num != 1)
        fac[num] = 1;

    for(auto it = fac.begin(); it != fac.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    ////rec(num, left_count);
    ////rec(num, left_count);
    lli c = rec(d, n);
    double ans = c;
    REP(i, n) {
        ans = ans / 6.0;
    }

    //cout << c << endl;
    cout << ans << endl;
}
