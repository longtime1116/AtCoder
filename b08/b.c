#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define REP(i, n)   for(i = 0; i < n; i++)

int     n, m;

int main (void)
{
    int     i, j;
    int     number = 0;
    string  name;
    map<string, int> map;
    cin >> n;

    string ans;
    REP(i, n) {
        cin >> name;
        map[name] += 1;
        if ( number < map[name] )
        {
            number = map[name];
            ans = name;
        }
    }
    cout << ans << endl;


    return 0;
}
