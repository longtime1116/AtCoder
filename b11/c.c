#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define REP(i, n)   for(i = 0; i < n; i++)

int     n, m;

int main (void)
{
    int     i, j;
    int     N, ng1, ng2, ng3, nextN;
    int     NG[3];
    cin >> N;

    REP(i, 3) {
        cin >> NG[i];
    }

    ng1 = NG[2];
    ng2 = NG[1];
    ng3 = NG[0];

    if ( ng1 == N || ng2 == N || ng3 == N ) {
        cout << "NO" << endl;
        return 0;
    }

    REP(i, 100) {
        N -= 3;
        if ( N == ng1 || N == ng2 || N == ng3 ) {
            N += 1;
        }
        if ( N == ng1 || N == ng2 || N == ng3 ) {
            N += 1;
        }
        if ( N == ng1 || N == ng2 || N == ng3 ) {
            N += 1;
        }
    }

    if ( N <= 0 )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

