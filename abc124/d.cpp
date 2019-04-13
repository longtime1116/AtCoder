#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    int n, k, ans=0;
    vector<int> s2;
    vector<int> s2_01;
    string s;
    cin >> n >> k;
    cin >> s;

    int count = 0;
    bool is_0;
    bool first_is_0;
    if (s[0] == '0')
        first_is_0 = is_0 = true;
    else
        first_is_0 = is_0 = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && is_0 || s[i] == '1' && !is_0) {

            count++;
        }
        else {
            s2.push_back(count);
            count = 1;
            is_0 = !is_0;
        }
    }
    s2.push_back(count);

    int s2_size = (int)s2.size();
    //for (int i = 0; i < s2_size; i++) {
        //cout << s2[i];
    //}
    //cout << endl;


    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < s2_size; i++) {
        int left, right;
        if (i % 2 != first_is_0) {
            left = i;
            right = min(left + k*2-1, s2_size -1);
        }
        else {
            left = i;
            right = min(left + k*2, s2_size -1);
        }
        int num = 0;
        for (int l = left; l < right + 1; l++) {
            num += s2[l];
        }
        if (ans < num)
            ans = num;
    }



    cout << ans << endl;
}
