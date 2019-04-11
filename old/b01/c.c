#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum direction {
    N = 0,
    NNE,
    NE,
    ENE,
    E,
    ESE,
    SE,
    SSE,
    S,
    SSW,
    SW,
    WSW,
    W,
    WNW,
    NW,
    NNW
} direction;


int main (void)
{
    double  deg = 0;
    double  dis = 0;
    char    dir[4];
    int     w;

    scanf("%lf %lf", &deg, &dis);

    deg = (deg/10 + 11.25) / 22.5;
    dis = ((double)(int)(dis /6 + 0.5))  / 10;

    switch ( (int)deg )
    {
        case N:
            strcpy(dir, "N");
            break;
        case NNE:
            strcpy(dir, "NNE");
            break;
        case NE:
            strcpy(dir, "NE");
            break;
        case ENE:
            strcpy(dir, "ENE");
            break;
        case E:
            strcpy(dir, "E");
            break;
        case ESE:
            strcpy(dir, "ESE");
            break;
        case SE:
            strcpy(dir, "SE");
            break;
        case SSE:
            strcpy(dir, "SSE");
            break;
        case S:
            strcpy(dir, "S");
            break;
        case SSW:
            strcpy(dir, "SSW");
            break;
        case SW:
            strcpy(dir, "SW");
            break;
        case WSW:
            strcpy(dir, "WSW");
            break;
        case W:
            strcpy(dir, "W");
            break;
        case WNW:
            strcpy(dir, "WNW");
            break;
        case NW:
            strcpy(dir, "NW");
            break;
        case NNW:
            strcpy(dir, "NNW");
            break;
        default:
            strcpy(dir, "N");
            break;
    }

    if ( dis <= 0.2 )
    {
        strcpy(dir, "C");
        w = 0;
    }
    else if ( dis <= 1.5 )
        w = 1;
    else if ( dis <= 3.3 )
        w = 2;
    else if ( dis <= 5.4 )
        w = 3;
    else if ( dis <= 7.9 )
        w = 4;
    else if ( dis <= 10.7 )
        w = 5;
    else if ( dis <= 13.8 )
        w = 6;
    else if ( dis <= 17.1 )
        w = 7;
    else if ( dis <= 20.7 )
        w = 8;
    else if ( dis <= 24.4 )
        w = 9;
    else if ( dis <= 28.4 )
        w = 10;
    else if ( dis <= 32.6 )
        w = 11;
    else
        w = 12;

    printf("%s %d\n", dir, w);

    return 0;
}
