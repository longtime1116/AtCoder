#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
int main() {

    int n;
    cin >> n;

    vector<P> ranges;
    for (int i = 0; i < n; i++) {
        //scanf("%d-%d", &ranges[i].first, &ranges[i].second);
        //cout << ranges[i].first;
        int start, end;
        scanf("%d-%d", &start, &end);
        start -= start % 5;
        if (end % 5 != 0) {
            end += 5 - end % 5;
            if (end % 100 == 60)
                end += 40;
        }
        ranges.push_back(P(start, end));
    }

    if (n==1) {
        printf("%04d-%04d\n", ranges[0].first, ranges[0].second);
        return 0;
    }

    sort(ranges.begin(), ranges.end());
    //for (int i = 0; i < n; i++) {
    //    cout << ranges[i].first << ranges[i].second << endl;
    //}
    vector<P> results;
    P p(ranges[0].first, ranges[0].second);
    for (int i = 0; i < n-1; i++) {
        int next_s = ranges[i+1].first;
        int next_e = ranges[i+1].second;

        if (p.second >= next_s) {
            //cout << "connect" << endl;
            //cout << p.first << "-" << p.second << endl;
            p.second = max(p.second, next_e);
        }
        else {
            //cout << "push" << endl;
            //cout << p.first << "-" << p.second << endl;
            results.push_back(P(p.first, p.second));
            p.first = p.second = -1;
        }

        if (p.first == -1) {
            p.first = next_s;
            p.second = next_e;
        }
    }
    results.push_back(P(p.first, p.second));

    for (int i=0; i < (int)results.size(); i++) {
        printf("%04d-%04d\n", results[i].first, results[i].second);
    }
}
