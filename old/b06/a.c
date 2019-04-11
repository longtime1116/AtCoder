#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main (void)
{
    int     a;

    cin >> a;

    if ( a == 3 || a == 6 || a == 9 )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
