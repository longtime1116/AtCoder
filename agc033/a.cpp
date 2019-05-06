#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


int a[1002][1002];

int main() {
    int h, w;
    cin >> h>>w;
    vector<P> v;
    lli true_count = 0;

    for(int i=0;i<h+2;i++) {
        for(int j=0;j<w+2;j++) {
            if (i == 0 || i == h+1 || j == 0 || j == w+1 ) {
                a[i][j] = 10001;
                continue;
            }
            char x;
            cin >> x;
            if (x == '#') {
                a[i][j] = 0;
                true_count++;
                v.push_back(P(i, j));

            }
            else
                a[i][j] = 10000;
        }
    }


    //解法2
    int ans = 0;
    while (true) {
        if (true_count == h*w)
            break;
        //cout <<"true_count: " <<  true_count << endl;
        ans++;

        vector<P> v2(v.size());
        copy(v.begin(), v.end(), v2.begin());
        v.clear();

        for (auto it = v2.begin(); it != v2.end(); it++) {
            int i = (*it).first;
            int j = (*it).second;
            //cout << "i: " << i << ", j: " << j << endl;
            if (a[i-1][j]==10000) {
                a[i-1][j] = ans;
                v.push_back(P(i-1, j));
                true_count++;
            }
            if (a[i+1][j]==10000) {
                a[i+1][j] = ans;
                v.push_back(P(i+1, j));
                true_count++;
            }
            if (a[i][j-1]==10000) {
                a[i][j-1] = ans;
                v.push_back(P(i, j-1));
                true_count++;
            }
            if (a[i][j+1]==10000) {
                a[i][j+1] = ans;
                v.push_back(P(i, j+1));
                true_count++;
            }
        }
        //for(int i=1;i<h+1;i++) {
        //    for(int j=1;j<w+1;j++) {
        //        if (a[i][j] < 10000)
        //            cout << "#";
        //        else
        //            cout << ".";
        //    }
        //    cout << endl;
        //}
        //cout << endl;
    }




    // 解法1
    //int ans = 0;
    //while (true) {
    //    //cout << "ans: " << ans << endl;
    //    if (true_count == h*w)
    //        break;
    //    ans++;
    //    for(int i=1;i<h+1;i++) {
    //        for(int j=1;j<w+1;j++) {
    //            if (a[i][j]<=ans)
    //                continue;
    //            if (a[i-1][j] < ans || a[i][j+1] < ans || a[i+1][j] < ans || a[i][j-1] < ans) {
    //                a[i][j] = ans;
    //                true_count++;
    //            }
    //        }
    //    }
    //    //for(int i=1;i<h+1;i++) {
    //    //    for(int j=1;j<w+1;j++) {
    //    //        if (a[i][j] < 10000)
    //    //            cout << "#";
    //    //        else
    //    //            cout << ".";
    //    //    }
    //    //    cout << endl;
    //    //}
    //    //cout << endl;
    //}

    // 解法3
    // 最も近い距離にある#を探していく
    //int ans = 0;
    //for (auto it = v.begin(); it != v.end(); it++) {
    //    int i = (*it).first;
    //    int j = (*it).second;
    //    //cout << "i: " << i << ", j: " << j << endl;


    //}


    //for(int i=1;i<h+1;i++) {
    //    for(int j=1;j<w+1;j++) {
    //        // a[i][j] から最も近いものを探す
    //        if (a[i][j]<=ans)
    //            continue;
    //        if (a[i-1][j] < ans || a[i][j+1] < ans || a[i+1][j] < ans || a[i][j-1] < ans) {
    //            a[i][j] = ans;
    //            true_count++;
    //        }
    //    }
    //}
    //for(int i=1;i<h+1;i++) {
    //    for(int j=1;j<w+1;j++) {
    //        if (a[i][j] < 10000)
    //            cout << "#";
    //        else
    //            cout << ".";
    //    }
    //    cout << endl;
    //}
    //cout << endl;

    //for(int i=1;i<h+1;i++) {
    //    for(int j=1;j<w+1;j++) {
    //        if (a[i][j])
    //            cout << "#";
    //        else
    //            cout << ".";
    //    }
    //    cout << endl;
    //}
    cout << ans << endl;
}
