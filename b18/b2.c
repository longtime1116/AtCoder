#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

void swap(
    char    *a,
    char    *b)
{
    char    temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



int main (void)
{
    string  str;
    int     n, i, j;
    
    cin >> str;
    cin >> n;

    int     l[n];
    int     r[n];

    for (i = 0; i < n; i++)
    {
        cin >> l[i];
        cin >> r[i];
        l[i]--;
        r[i]--;
    }

    for (i = 0; i < n; i++)
    {
        int m = (l[i] + r[i]) /2;
        for ( j = l[i]; j < m + 1 ; j++)
        {
            swap(str[j], str[r[i]]);
            r[i]--;
        }
    }

    cout << str << endl;

    return 0;
}
