#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main (void)
{
    int     t, n, m;
    int     i, j;
    bool    result = true;

    cin >> t >> n;

    int     a[n];
    for ( i = 0; i < n; i++ )
        cin >> a[i];

    cin >> m;
    int     b[m];
    for ( i = 0; i < m; i++ )
        cin >> b[i];

    i = 0;
    for ( j = 0; j < m; j++ )
    {
        if ( n - i < m - j )
        {
            result = false;
            goto END;
        }
       for ( ; i < n; i++ )
        {
            if ( b[j] >= a[i] && b[j] <= a[i] + t )
            {
                i++;
                break;
            }
            if ( b[j] < a[i] || i == n - 1 )
            {
                result = false;
                goto END;
            }

        }
    }

END:
    if ( result == false )
        cout << "no" << endl;
    else
        cout << "yes" << endl;

    return 0;
}
