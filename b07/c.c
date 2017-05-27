#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
#define MAX1        (50)
#define MAX2        (50)

#define REP(i, n)   for(i = 0; i < n; i++)

#define INF         (1000000)

char    maze[MAX1][MAX2+1];
int     r, c;
int     i, j;
int     sx, sy, gx, gy;
int     dx[4] = {1, 0, -1, 0};
int     dy[4] = {0, 1, 0, -1};
int     path[MAX1][MAX2];


int bfs (void)
{
    int nx, ny;
    queue< pair<int, int> > que;

    REP(i, r) {
        REP(j, c) {
            path[i][j] = INF;
        }
    }

    que.push(pair<int, int>(sx, sy));
    path[sx][sy] = 0;

    while( que.size() ) {
        pair<int, int> p = que.front();
        que.pop();
        
        if ( p.first == gx && p.second ==gy ) {
            break;
        }
        REP(i, 4) {
            nx = p.first + dx[i];
            ny = p.second + dy[i];

            if ( nx >= 0 && nx <= r && ny >= 0 && ny <= c && maze[nx][ny] != '#' && path[nx][ny] == INF ) {
                que.push(pair<int, int>(nx, ny));
                path[nx][ny] = path[p.first][p.second] + 1;
            }
        }

    }

    return path[gx][gy];
}


int main (void)
{

    cin >> r >> c >> sx >> sy >> gx >> gy;

    sx--;
    sy--;
    gx--;
    gy--;

    REP(i,r) {
        REP(j, c) {
            cin >> maze[i][j];
        }
    }

    int     result = bfs();

    cout << result << endl;

    return 0;
}
