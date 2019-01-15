#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int cnt[N][541];
    fill(cnt[0], cnt[N], 0);
    // cnt[i][l] = iを端点とした長さl+1000の線路の数
    // iは0-indexed

    for (int i = 0; i < M; i++) {
        int A, B, L;
        cin >> A >> B >> L;

        if (L > 1540) continue;
        // 1540より長い線路は使えないので無視

        A--, B--;
        cnt[A][L - 1000]++;
        cnt[B][L - 1000]++;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int l = 0; l < 270; ++l) {
            ans += cnt[i][l] * cnt[i][540 - l];
        }

        // 1270同士をくっつける場合だけ例外
        // 同じ線路をくっつけてしまう場合がある
        ans += cnt[i][270] * (cnt[i][270] - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}
