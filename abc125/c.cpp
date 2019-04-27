#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int A[100000];
int R[100000];
int L[100000];
int n;

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    int r;
      r = a % b;

  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int calc_l(int max_i) {
    if (max_i < 0)
        return 0;
    if (L[max_i] != 0)
        return L[max_i];
    if (max_i == 0)
        return L[0] = A[0];
    return L[max_i] = gcd(calc_l(max_i-1), A[max_i]);
}

int calc_r(int min_i) {
    if (min_i > n-1)
        return 0;
    if (R[min_i] != 0)
        return R[min_i];
    if (min_i == n-1)
        return R[n-1] = A[n-1];
    return R[min_i] = gcd(calc_r(min_i+1), A[min_i]);
}

int exclude_gcd(int ex_i) {
    return gcd(calc_l(ex_i-1), calc_r(ex_i+1));
}

int main() {
    cin >> n;
    REP(i, n) {
        cin >> A[i];
    }
    int max_gcd = 0;

    // i を除いたときのgcd
    REP(i, n) {
        int cur_gcd = exclude_gcd(i);
        max_gcd = max(max_gcd, cur_gcd);
    }
    cout << max_gcd << endl;
}
