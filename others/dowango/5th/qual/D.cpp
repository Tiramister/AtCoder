#include <iostream>

using namespace std;

using ll = long long;

const ll INF = 1LL << 30;

int main() {
    int N, D;
    cin >> N >> D;

    ll cnt[D][D];
    fill(cnt[0], cnt[D], 0);

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        ++cnt[x % D][y % D];
    }

    ll ok = INF, ng = 0;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;

        bool judge = false;
        for (ll bx = 0; bx < D; ++bx) {
            for (ll by = 0; by < D; ++by) {
                // [bx, bx + mid) X [by, by + mid)に入るか？

                bool injudge = true;
                for (ll x = bx; x < bx + D; ++x) {
                    for (ll y = by; y < by + D; ++y) {
                        ll putable = ((bx + mid - x) / D + 1) * ((by + mid - y) / D + 1);
                        if (bx + mid < x || by + mid < y) putable = 0;
                        if (putable < cnt[x % D][y % D]) {
                            injudge = false;
                        }
                    }
                }

                if (injudge) judge = true;
            }
        }

        if (judge) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}
