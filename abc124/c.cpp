#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int main() {
    string s;
    cin >> s;
    int size = (int)s.length();
    int first_0 = 0, first_1 = 0;

    bool is_0 = false;
    for (int i = 0; i < size; i++) {
        if (is_0) {
            if (s[i] != '0')
                first_0++;
            //cout << "a" << endl;
            //cout << s[i] << endl;
            //cout << i << endl;
        }
        else {
            if (s[i] != '1')
                first_0++;
            //cout << "b" << endl;
            //cout << s[i] << endl;
            //cout << i << endl;
        }
        is_0 = !is_0;
    }

    is_0 = true;
    for (int i = 0; i < size; i++) {
        if (is_0) {
            if (s[i] != '0')
                first_1++;
            //cout << "c" << endl;
            //cout << s[i] << endl;
            //cout << i << endl;
        }
        else {
            if (s[i] != '1')
                first_1++;
            //cout << "d" << endl;
            //cout << s[i] << endl;
            //cout << i << endl;
        }
        is_0 = !is_0;
    }
    //cout << first_0 << endl;
    //cout << first_1 << endl;

    cout << min(first_0, first_1) << endl;
}
