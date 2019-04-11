#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main (void)
{
    string      str[4];
    int    i;

    for ( i = 0; i < 4; i++ )
        getline(cin, str[i]);

    for ( i = 3; i >= 0; i--)
    {
        reverse(str[i].begin(), str[i].end());
        cout << str[i] << endl;
    }
    return 0;
}
