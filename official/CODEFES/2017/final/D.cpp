#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

const ll INF = 1LL << 50;

// ソート用比較関数
bool sumcmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first + a.second < b.first + b.second;
}

ll dp[5010][5010];

int main() {
    int N;
    cin >> N;

    pair<ll, ll> hp[N];
    for (int i = 0; i < N; ++i) {
        cin >> hp[i].first >> hp[i].second;
    }

    // ペアの和について昇順にソート
    sort(hp, hp + N, sumcmp);

    fill(dp[0], dp[0] + N + 1, INF);
    dp[0][0] = 0, dp[0][1] = hp[0].second;
    // dp[i][j] = i人目まででj人を選んだときの,Pの総和の最小値
    // 0人目は絶対置けるので初期化

    for (int i = 1; i < N; ++i) {
        // i人目を選ばない場合
        for (int j = 0; j <= N; ++j) {
            dp[i][j] = dp[i - 1][j];
        }

        // i人目を選ぶ場合
        for (int j = 0; j < N; ++j) {
            if (dp[i - 1][j] <= hp[i].first) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + hp[i].second);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= N; ++j) {
        if (dp[N - 1][j] < INF) ans = j;
    }

    cout << ans << endl;
    return 0;
}
