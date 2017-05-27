#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main (void)
{
    int     n, fast = 100;
    int     i;
    int     sec;

    cin >> n;

    for ( i = 0; i < n; i++ )
    {
        cin >> sec;
        if ( sec < fast )
            fast = sec;
    }

        cout << fast << endl;

    return 0;
}
