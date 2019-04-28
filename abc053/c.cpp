#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    lli x;
    cin >> x;
    lli count = (x/11)*2 ;
    double remain = x % 11;
    if (remain > 0){
        count += 1;
    }
    if (remain > 6){
        count += 1;
    }
    cout << count << endl;
}


// 17 =>  6,5,6
