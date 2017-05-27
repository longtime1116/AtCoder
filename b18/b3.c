#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

int main (void)
{
    string  str;
    int     n, i;
    
    cin >> str;
    cin >> n;

    int     l,r;

    for (i = 0; i < n; i++)
    {
        cin >> l >> r;
        l--;
        reverse(str.begin() + l, str.begin() + r);
    }

    cout << str << endl;

    return 0;
}
