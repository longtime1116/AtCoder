#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX1        (100)
#define MAX2        (100)

#define REP(i, n)   for(i = 0; i < n; i++)

int     n, k;


int dosort(
    string *before,
    string *str)
{
    int     i, temp[n], j=0;

    memset(temp, 0, sizeof(temp));
    string  tempstr;
    REP(i, n) {

        if ( (*before)[i] != (*str)[i] ) {
            tempstr += (*str)[i];
            temp[j] = i;
            j++;
        }
    }

    sort(tempstr.begin(), tempstr.end());

    for ( int k = 0; k < j; k++ ) {
        (*str)[temp[k]] = tempstr[k];
    }

    return 1;
}


int calc (
    string before,
    string str)
{
    int     i;
    int     num = 0;
    REP(i, n){
        if (str[i] != before[i]) {
            num++;
        }
    }
    return num;

}

int main (void)
{
    int     i, j, l, changed = 0;
    char    s, temp;
    bool    is_end = false;
    cin >> n >> k;

    string  before, str, prestr, sorted;

    cin >> before;
    str = before;
    sorted = str;
    sort(sorted.begin(), sorted.end());
    REP(i, n){
        for ( j = 0; j < n; j++ ) {

            // もうこれ以上変更不可能なら終わり
            if ( k == changed )
                goto END;

            s = sorted[j];

            // 既に str.i 番目の文字は理想的な壱にいる
            if ( str[i] == s )
                break;

            // str.i 番目の位置に sort.j 番目の文字を持ってくる
            for ( l = n-1; l > i; l-- ) {

                if ( str[l] == s )
                {
                    prestr = str;
                    // switch
                    temp = str[i];
                    str[i] = s;
                    str[l] = temp;
                    // 元から位置の変わったものの個数を算出
                    changed = calc(before, str);
                    if ( k < changed ) {
                        //元に戻して sorted の次の文字へ
                        str = prestr;
                        continue;
                    }
                    // i 番目の文字確定
                    dosort(&before, &str);
                    is_end = true;
                    break;
                }
            }
            if ( is_end ) {
                is_end = false;
                break;
            }
        }
    }
END:
    cout << str << endl;

    return 0;
}
