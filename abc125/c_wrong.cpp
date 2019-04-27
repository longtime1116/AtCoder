#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int gcds[100000];
int A[10000];
int tmp[10000];
int n;

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    int r;
      r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

void do_gcd(int step, bool first) {
    for (int i =0; i < n; i += step) {
        int next_i = i+step/2;
        if (next_i > n-1)
            continue;
        tmp[i] = gcd(tmp[i], tmp[next_i]);
    }

}

int exclude_gcd(int ex_i) {
    int step = 2;
    bool first = true;

    // tmp 初期化
    REP(i, n) {
        tmp[i] = A[i];
    }
    int alt = ex_i - 1;
    if (ex_i == 0)
        alt = 1;

    tmp[ex_i] = tmp[alt];
    while(true) {
        //cout << "step: " << step << endl;
        do_gcd(step, first);
        first = false;

        //cout << "[";
        //for (int i = 0; i < n; i++)
            //cout << tmp[i] << ",";
        //cout << "]" << endl;

        step *= 2;
        if (step/2>n)
            break;
    }

    return tmp[0];
}

int main() {
    cin >> n;
    REP(i, n) {
        cin >> A[i];
    }
    int max_gcd = 0;
    // i を除いたときのgcd
    REP(i, n) {
        //cout << "---------" << endl;
        int cur_gcd = exclude_gcd(i);
        //cout << "cur : ";
        //cout << cur_gcd << endl;
        max_gcd = max(max_gcd, cur_gcd);
    }
    cout << max_gcd << endl;
}
