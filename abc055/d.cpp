#include <bits/stdc++.h>
using namespace std;

// iterator
#define REP(i,init, n) for(lli i=init;i<n;i++)
#define REPE(i,init, n) for(lli i=init;i<=n;i++)
#define REPIT(it,container) for(auto it = container.begin(); it != container.end(); it++)
#define REPIT_R(it,container) for(auto it = container.rbegin(); it != container.rend(); it++)

// input
#define cin1(x)             cin >> x
#define cin2(x, y)          cin >> x >> y
#define cin3(x, y, z)       cin >> x >> y >> z
#define ncin1(n, x)         REP(i, 0, n) {cin1(x[i]);}
#define ncin2(n, x, y)      REP(i, 0, n) {cin2(x[i], y[i]);}
#define ncin3(n, x, y, z)   REP(i, 0, n) {cin3(x[i], y[i], z[i]);}

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

typedef long long int lli;
typedef pair<lli, lli> P;

lli colors[100001];


lli n;
string s;

bool is_bipartite(lli target) {
    lli prev = (target + n - 1) % n;
    lli next = (target + 1) % n;

    lli next_color = 0;

    if (s[target] == 'o') {
        if (colors[target] == 1)
            next_color = colors[prev];
        else
            next_color = -colors[prev];
    }
    else {
        if (colors[target] == 1)
            next_color = -colors[prev];
        else
            next_color = colors[prev];
    }


    if (colors[next] != 0) {
        if (colors[next] != next_color)
            return false;
        lli nexxt = (next + 1) % n;
        // s[next] が矛盾していないか？
        if (s[next] == 'o') {
            if (colors[next] == 1) {
                return colors[target] == colors[nexxt];
            }
            else {
                return colors[target] != colors[nexxt];
            }
        }
        else {
            if (colors[next] == 1) {
                return colors[target] != colors[nexxt];
            }
            else {
                return colors[target] == colors[nexxt];
            }
        }
    }

    colors[next] = next_color;
    return is_bipartite(next);
}

void init() {
    REP(i, 0, 100001){
        colors[i] = 0;
    }
}

int main() {
    cin1(n);
    cin1(s);

    // 1 が羊

    if (s[0] == 'o') {
        // 0 が羊で、しかも両側は羊か狼のどちらか
        colors[0] = 1;
        colors[1] = 1;
        colors[n-1] = 1;
        if (is_bipartite(1))
            goto SUCCESS;

        init();
        colors[0] = 1;
        colors[1] = -1;
        colors[n-1] = -1;
        if (is_bipartite(1))
            goto SUCCESS;

        init();
        colors[0] = -1;
        colors[1] = 1;
        colors[n-1] = -1;
        if (is_bipartite(1))
            goto SUCCESS;

        init();
        colors[0] = -1;
        colors[1] = -1;
        colors[n-1] = 1;
        if (is_bipartite(1))
            goto SUCCESS;
    }
    else {
        colors[0] = 1;
        colors[1] = 1;
        colors[n-1] = -1;
        if (is_bipartite(1))
            goto SUCCESS;

        init();
        colors[0] = 1;
        colors[1] = -1;
        colors[n-1] = 1;
        if (is_bipartite(1))
            goto SUCCESS;

        init();
        colors[0] = -1;
        colors[1] = 1;
        colors[n-1] = 1;
        if (is_bipartite(1))
            goto SUCCESS;

        init();
        colors[0] = -1;
        colors[1] = -1;
        colors[n-1] = -1;
        if (is_bipartite(1))
            goto SUCCESS;

    }

    cout << -1 << endl;
    return 0;

SUCCESS:
    REP(i, 0, n) {
        if (colors[i] == 1)
            cout << "S";
        else
            cout << "W";
    }
    cout << endl;
    return 0;
}
