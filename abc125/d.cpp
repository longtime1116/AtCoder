#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;
    int m_count = 0;
    int min_positive = INT_MAX;
    int num;
    lli total = 0;
    REP(i, n) {
        cin >> num;
        if (num < 0) {
            m_count++;
            num = -num;
        }
        min_positive = min(min_positive, num);
        total += num;
    }
    if (m_count % 2 == 1)
        cout << total - min_positive * 2 << endl;
    else
        cout << total << endl;
}
