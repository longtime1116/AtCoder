#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

bool done[30004];

// NOTE: ルールベースでやろうとして失敗した
int main() {
    int n;
    cin >> n;
    list<int> x;
    int c[n];
    REP(i, n) {
        cin >> c[i];
        //x.push_back(c);
    }
    lli count = 0;
    lli target = 1;
    for(int i=0;i<n;i++) {
        if (done[target]) {
            target++;
            i--;
            if (target == n+1)
                break;
        }
        if (c[i] < target)
            continue;
        else if (c[i] == target) {
            target++;
            if (target != n+1)
                continue;
            break;
        }
        else {
            // c[i+1] が target のときはc[i]を抜く
            if (c[i+1] == target) {
                count++;
                target++;
                done[c[i]] = true;
                i++;
            }
            else {
                done[target] = true;
                count++;
                target++;
                i--;
            }
            if (target == n+1)
                break;
        }

    }
    //lli count = 0;
    //lli target = 1;
    //auto it = x.begin();
    //while(true) {
    //    if (*it < target ) {
    //        it++;
    //        continue;
    //    }
    //    else if (*it == target) {
    //        it++;
    //        target++;
    //        if (target == n + 1)
    //            break;
    //        else
    //            continue;
    //    }
    //    else {
    //        target++;
    //        count++;
    //    }

    //}
    cout << count << endl;
}
