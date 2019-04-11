#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void step2(
    int     *card,
    int     r)
{
    int     temp;
    int     i;

    temp = card[0];

    for ( i = 0; i < r; i++)
        card[i] = card[i + 1];

    card[r] = temp;
}


void step1(
    int     *card,
    int     q)
{
    int     temp[5];
    int     i, j = 0;

    for ( i = 0; i < q; i++ )
        temp[i] = card[i];

    for ( i = q; i < 6; i++ )
    {
        card[j] = card[i];
        j++;
    }

    j = 0;
    for ( i = 6 - q; i < 6; i++ )
    {
        card[i] = temp[j];
        j++;
    }
}




int main (void)
{
    int     n, n_m30, q, r;
    int     card[6];
    int     i;

    for (i = 0; i < 6; i++)
        card[i] = i + 1;

    cin >> n;

    n_m30 = n % 30;
    q = n_m30 / 5;
    r = n_m30 % 5;

    step1(card, q);

    step2(card, r);

    for ( i = 0; i < 6; i++ )
        cout << card[i];
    cout << endl;

return 0;
}
