#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    ll X[M];
    for (ll i = 0; i < M; ++i) {
        cin >> X[i];
    }

    ll ng = -1, ok = N * 2;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;

        ll l = 1;
        // 未整備な車両で一番左のもの

        for (ll i = 0; i < M; ++i) {
            // X[i]が整備済みの場合
            if (X[i] < l) {
                l = X[i] + mid + 1;
                continue;
            }

            // 未整備の車両に到達できない場合
            if (X[i] - l > mid) break;

            // lまで行って行けるだけ進む
            // 行けるだけ進んでからlまで戻る
            l = X[i] + 1 + max(mid - (X[i] - l) * 2, (mid - (X[i] - l)) / 2);
        }

        if (l > N) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}
