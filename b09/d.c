#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define MP          make_pair

#define REP(i, n)   for(i = 0; i < n; i++)

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, pii> ppp;
typedef long long ll;
typedef unsigned long long ull;


ull      K, M;

ull dfs(
    ull M,
    ull *A,
    ull *C)
{
    unsigned int i;
    
    if (A[M] != 0) {
        return A[M];
    }

    REP(i, K) {
        A[M - 1 - i] = dfs(M - 1 - i, A, C);
    }
    // (C[M-1] AND A[M-1]) XOR ... の計算
    ull res = 0;
    REP(i, K) {
        res ^= C[i] & A[M - 1 - i];
    }
    A[M] = res;
    return  A[M];
}


int main (void)
{
    unsigned int     i, j;
    cin >> K >> M;

    ull     A[M], C[K];

    memset(A, 0, sizeof(A));
    REP(i, K) {
        cin >> A[i];
    }

    REP(i, K) {
        cin >> C[i];
    }
    // M の inde を 0 オリジンに
    M--;
    cout << dfs(M, A, C) << endl;


    return 0;
}
