#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


// dp[i][j]: ai、bj まで使った状態での価値の最大値
//lli dp[1001][1001];
int main() {
    int A, B;
    cin >> A >> B;
    lli a[A];
    lli b[B];
    REP(i, A) {
        cin >> a[i];
    }
    REP(i, B) {
        cin >> b[i];
    }

    lli ans = 1;
    int a_count = 0;
    int b_count = 0;
    lli score = 0;
    lli b_score = 0;
    bool my_turn = true;
    for(int i=1;i<=A+B;i++) {
        if (a_count == A-1) {
            // a は存在しない => b をとる
            if (my_turn) {
                score += b[b_count];
            }
            b_count++;
        }
        else if (b_count == B-1) {
            // b は存在しない => a をとる
            if (my_turn) {
                score += a[a_count];
            }
            a_count++;
        }
        else {
            // a も b も残っている => 計算
            // a も b も残り 1 個
            lli a_benefit = a[a_count] - max(a[a_count+1, b[b_count]]);
            lli b_benefit = b[a_count] - max(b[b_count+1, a[a_count]]);
            if (a_benefit > b_benefit) {
                if (my_turn)
                    score += a[a_count];
                a_count++;
            }
            else {
                if (my_turn)
                    score += b[b_count];
                b_count++;
            }
        }
        my_turn = !my_turn;
    }

    //for(int i=0;i<=A;i++) {
    //    for (int j=0; j<=B; j++) {
    //        // 相手のターン
    //        if ((i + j) % 2 == 1) {
    //            // a を使う
    //            if (i < A)
    //                dp[i+1][j] = dp[i][j];
    //            // b を使う
    //            if (j < B)
    //                dp[i][j+1] = dp[i][j];
    //        }
    //        else {
    //            // a を使う
    //            if (i < A)
    //                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i]);
    //            // b を使う
    //            if (j < B)
    //                dp[i][j+1] = max(dp[i][j+1], dp[i][j] + b[j]);
    //            //if (i == 0 && j == 1) {
    //            //    cout << "dp["<<i<<"]["<<j<<"]: " << dp[i][j]<<endl;
    //            //    cout << "dp["<<i<<"]["<<j+1<<"]: " << dp[i][j+1]<<endl;
    //            //    cout << "dp["<<i+1<<"]["<<j<<"]: " << dp[i+1][j]<<endl;
    //            //}
    //        }
    //    }
    //}

    for(int i=0;i<=A;i++) {
        for (int j=0; j<=B; j++) {
            cout << "dp["<<i<<"]["<<j<<"]: " << dp[i][j]<<endl;
        }
    }


    cout << dp[A][B] << endl;
}
