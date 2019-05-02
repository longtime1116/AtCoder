#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<lli, lli> P;

lli dp[2][200001];

int main() {
    lli N, W;
    cin >> N >> W;
    lli v[N];
    lli w[N];
    lli max_v = 0;
    lli max_w = 0;
    lli ans = 0;
    REP(i, N) {
        cin >> v[i] >> w[i];
        max_v = max(max_v, v[i]);
        max_w = max(max_w, w[i]);
    }
    if (max_w <= 1000) {
    //if (false) {
        // w が 1 <= w <= 1000 を満たすときは、重さの総和は MAX 200000 なので、dp でいける
        // dp[i][j]: i 個目まで使える条件のもと重さの総和を j にするときの最大の価値
        bool pos = false;
        for(int i=0;i<N;i++){
            REP(j, W+1) {
                if (j-w[i]>=0)
                    dp[!pos][j] = max(dp[pos][j], (dp[pos][j-w[i]] + v[i]));
                else
                    dp[!pos][j] = dp[pos][j];
            }
            pos = !pos;
        }
        ans = dp[pos][W];
    }
    else if (max_v <= 1000) {
    //else if (false) {
        // v が 1 <= v <= 1000 を満たすときは、価値の総和は 200000 なので、dp でいける
        // dp[i][j]: i 個目まで使える条件のもと価値の総和を j にするときの最小の重さ
        REP(i, 2) {
            REP(j, 200001) {
                if (j == 0 )
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1000000001;
            }
        }
        bool pos = false;
        for(int i=0;i<N;i++){
            for(lli j=0;j<200001;j++) {
                if (j-v[i]>=0)
                    dp[!pos][j] = min(dp[pos][j], (dp[pos][j-v[i]] + w[i]));
                else
                    dp[!pos][j] = dp[pos][j];

                if (dp[!pos][j] <= W)
                    ans = max(ans, j);
            }
            pos = !pos;
        }
    }
    else {
        // N <= 30 の条件のみなので、dp はきつい
        // 全探索を考えるが、2^30 はきつい。
        // そこで、2^15 でふたつに分ける。2^15 くらいならいける。
        // 前者後者両方で、2^15 通りの組み合わせを用意し、あとはそれぞれを組み合わせる。
        // 組み合わせは O(nlogn) でいける(ソートして二分探索)。ので、全体のオーダーは O(2^(N/2))となり、間に合う

        // 2つに分けて、m = n/2 としたときに 2^m 個ずつのものを用意し、その組み合わせをマージ
        map<lli, lli> former;
        map<lli, lli> latter;
        vector<P> wv_1;
        vector<P> wv_2_tmp, wv_2;

        // 2^m 通りを列挙
        REP(i, (1<<N/2)) {
            lli total_v = 0;
            lli total_w = 0;
            // j bit 目 が立っていたら v[j] が選ばれている
            REP(j, (N/2)) {
                if ((i&(1<<j)) != 0) {
                    total_v += v[j];
                    total_w += w[j];
                    //cout << "w added: " << w[j] << " (j: " <<j<< endl;
                }
            }
            //cout << "i: " << i << ", total_w: " << total_w << endl;
            if (total_w > W)
                continue;
            if (former.count(total_w) == 0 || former[total_w] < total_v)
                former[total_w] = total_v;
        }
        for(auto it = former.begin(); it != former.end(); it++) {
            //cout << it->first << " " << it->second << endl;
            wv_1.push_back(P(it->first, it->second));
        }
        sort(wv_1.begin(), wv_1.end());
        //cout << "wv_1" << endl;
        REP(i, wv_1.size()) {
            //cout << "weight: " << wv_1[i].first << ", value: " << wv_1[i].second << endl;
        }

        //cout << "latter" << endl;
        //// 2^m 通りを列挙
        REP(i, (1<<(N-N/2))) {
            lli total_v = 0;
            lli total_w = 0;
            // j bit 目 が立っていたら v[j] が選ばれている
            REP(j, (N-N/2)) {
                if ((i&(1<<j)) != 0) {
                    total_v += v[j+N/2];
                    total_w += w[j+N/2];
                    //cout << "w added: " << w[j] << " (j: " <<j<< endl;
                }
            }
            //cout << "i: " << i << ", total_w: " << total_w << endl;
            if (total_w > W)
                continue;
            if (latter.count(total_w) == 0 || latter[total_w] < total_v)
                latter[total_w] = total_v;
        }
        for(auto it = latter.begin(); it != latter.end(); it++) {
            //cout << it->first << " " << it->second << endl;
            wv_2_tmp.push_back(P(it->first, it->second));
        }
        sort(wv_2_tmp.begin(), wv_2_tmp.end());
        lli prev = -1;
        //cout << "wv_2" << endl;
        REP(i, wv_2_tmp.size()) {
            if (prev < wv_2_tmp[i].second) {
                wv_2.push_back(P(wv_2_tmp[i].first, wv_2_tmp[i].second));
                prev = wv_2_tmp[i].second;
                //cout << "i: " << i << ", first: " << wv_2_tmp[i].first << ", second: " << wv_2_tmp[i].second << endl;
            }
        }

        REP(i, wv_1.size()) {
            auto it = upper_bound(wv_2.begin(), wv_2.end(), P(W-wv_1[i].first, LLONG_MAX));
            lli index = distance(wv_2.begin(), it);
            //cout << "wv_1 index: " << i << endl;
            //cout << "wv_2 index: " << index << endl;
            //cout << "wv_1  i: " << i << ", first: " << wv_1[i].first << ", second: " << wv_1[i].second << endl;
            //cout << "wv_2  i: " << i << ", first: " << wv_2[index-1].first << ", second: " << wv_2[index-1].second << endl;
            if (index - 1 >= 0)
                ans = max(ans, wv_1[i].second + wv_2[index-1].second);
        }
    }

    cout << ans << endl;
}
