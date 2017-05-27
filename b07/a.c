#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define REP(i, n)   for(i = 0; i < n; i++)

int     n;

int main (void)
{
    char    a[11] = {0};
    cin >> a;

    if (a[0] == 'a' && a[1] == 0) {
        cout << "-1" << endl;
    }
    else {
        cout << "a" << endl;
    }

    return 0;
}
