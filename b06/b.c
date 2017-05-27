#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;


int trib(
    int     n,
    int     *table)
{
    switch ( n ) {
      case 1:
        return 0;
        break;
      case 2:
        return 0;
        break;
      case 3:
        return 1;
        break;
      default:
       break;
    }
    if ( table[n] != 0 ) {
        return table[n];
    }
    table[n] = (trib(n-1, table) + trib(n-2, table) + trib(n-3, table)) % 10007;
    return table[n];
}


int main (void)
{
    int     n;
    int     a;

    cin >> n;
    int     table[n+2];
    memset(table, 0, sizeof(table));
    a = trib(n, table);
  
    cout << a << endl;
    return 0;
}
