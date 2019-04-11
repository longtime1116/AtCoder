#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

int main (void)
{
    char    str[101];
    int     i, j, k, n, x, y;
    
    cin >> str;
    cin >> n;

    int     l[n];
    int     r[n];

    for (i = 0; i < n; i++)
    {
        cin >> l[i];
        cin >> r[i];
    }

    for (i = 0; i < n; i++)
    {
        x = l[i];
        y = r[i];
        char    temp[101];

        for ( j = x-1; j < y ; j++)
            temp[j] = str[j];
        for ( k = x-1; k < y; k++ )
        {
            str[k] = temp[j-1];
            j--;
        }
    }

    cout << str << endl;

    return 0;
}
