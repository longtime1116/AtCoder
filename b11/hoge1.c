#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
 
const int MAX_N = 1000;
 
int dp[MAX_N + 10][2 * MAX_N + 10][2 * MAX_N + 10];
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
 
int N, D, X, Y;
 
int main() {
    cin >> N >> D >> X >> Y;
    if(X % D || Y % D) {
        cout << 0.0 << endl;
        exit(0);
    }
    X = X / D + 1000; Y = Y / D + 1000;
 
    int Xs = 1000, Ys = 1000;
 
    dp[0][Xs][Ys] = 1;
    for(int t = 1; t <= N; t++) {
        for(int x = 0; x < 2 * MAX_N + 10; x++) {
            for(int y = 0; y < 2 * MAX_N + 10; y++) {
                for(int i = 0; i < 4; i++) {
                    if(0 < x - dx[i] && x - dx[i] < 2 * MAX_N + 10 &&
                       0 < y - dy[i] && y - dy[i] < 2 * MAX_N + 10) {
                        dp[t][x][y] += dp[t - 1][x - dx[i]][y - dy[i]];
                    }
                }
            }
        }
    }
 
    cout << dp[N][X][Y] / pow(4.0, N)  << endl;
 
    return 0;
}
