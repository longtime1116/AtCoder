#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main (void)
{
    int     n, m;
    int     x, y, z, a;
    bool    f = false;

    cin >> n >> m;

    a = m - n * 2;

    for ( y=0; y<2; y++ ) {
        for ( z=0; z<n+1; z++ ) {
            if ( y + 2 * z == a ) {
                x = n -y -z;
                if ( x >= 0 ) {
                    f = true;
                    goto END;
                }
            }
        }
    }
END:
    if ( f == true ) {
        cout << x << " " << y << " " << z << endl;
    }
    else {
        cout << "-1 -1 -1" << endl;
    }

    return 0;
}
