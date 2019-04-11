#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int main (void)
{
    int     n, i;

    cin >> n;
    int     a[n+4];
    memset(a, 0, sizeof(a));
    a[2] = 1;
    for ( i = 3; i < n; i++ )
        a[i] = (a[i-1] + a[i-2] + a[i-3]) % 10007;
  
    cout << a[n-1] << endl;
    return 0;
}
