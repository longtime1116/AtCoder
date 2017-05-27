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
    if (n == 1 || n == 2) {
        cout << 0 << endl;
        return 0;
    }
    int     a[5];
    memset(a, 0, sizeof(a));
    a[2] = 1;
    for ( i = 3; i < n; i++ )
        a[i%4] = (a[(i-1)%4] + a[(i-2)%4] + a[(i-3)%4]) % 10007;
  
    cout << a[(i-1)%4] << endl;
    return 0;
}
