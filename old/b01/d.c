#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main (void)
{
    int     i;
    int     j;
    int     k;
    int     l;
    int     n;
    int     temp;
    int     *start;
    int     *end;
    int     st_h;
    int     st_m;
    int     end_h;
    int     end_m;

    scanf("%d", &n);

    start = (int *)malloc(sizeof(int) * n);
    end = (int *)malloc(sizeof(int) * n);


    // scanして時間をまるめる
    for ( i = 0; i < n; i++ )
    {
        scanf("%d-%d", &start[i], &end[i]);
        st_h = (int)(start[i]/100 ) * 100;
        st_m = start[i] - st_h;
        end_h = (int)(end[i]/100 ) * 100;
        end_m = end[i] - end_h;

        temp = st_m % 10;
        if ( temp < 5 )
            start[i] -= temp;
        else
            start[i] += 5 - temp;
        temp = end_m % 10;
        if ( temp != 0 && temp <= 5 )
            end[i] = end[i] + (5 - temp);
        if ( temp != 0 && temp > 5 )
        {
            end[i] = end[i] + (10 - temp);
            if ( end[i] % 100 == 60 )
                end[i] += 40;
         }

//         printf("%.4d-%.4d\n", start[i], end[i]);
    }

    // 時間でソート
    for ( i = 1; i < n; i = i * 3 + 1 )
        ;
    for (; i > 0; i /= 3 )
    {
        for ( j = i; j < n; j++ )
        {
            k = j;
            while ( k >= i && start[k - i] > start[k] )
            {
                l = start[k];
                start[k] = start[k - i];
                start[k - i] = l;
                l = end[k];
                end[k] = end[k - i];
                end[k - i] = l;
                k -= i;
            }
        }
    }

    // 重複している場合時間をマージ
    i = 0;
    j = 0;

    for ( i = 0; i < n - 1; i++ )
    {
        if ( end[i] >= start[i + 1] )
        {
            if (end[i] >= end[i + 1])
            {
                end[i + 1] = end[i];
            }
            start[i + 1]  = start[i];
            start[i] = -1;
        }
    }
        
    // 出力
    for ( i = 0; i < n; i++ )
    {
        if ( start[i] != -1 )
            printf("%.4d-%.4d\n", start[i], end[i]);
    }

    return 0;
}
