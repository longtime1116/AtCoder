#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main (void)
{
    int     a, b, c;

    cin >> a >> b >> c;

    if (a > b)
        if ( b > c )
            cout << 1 << endl << 2 << endl << 3 << endl;
        else
            if ( a > c )
                cout << 1 << endl << 3 << endl << 2 << endl;
            else
                cout << 2 << endl << 3 << endl << 1 << endl;
    else 
        if ( b < c )
            cout << 3 << endl << 2 << endl << 1 << endl;
        else
            if ( a > c )
                cout << 2 << endl << 1 << endl << 3 << endl;
            else
                cout << 3 << endl << 1 << endl << 2 << endl;

    return 0;
}
