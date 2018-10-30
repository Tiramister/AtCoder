#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll X;
    int K;
    cin >> X >> K;

    ll r[K + 1];
    r[0] = 0;
    for (int i = 1; i <= K; ++i) {
        cin >> r[i];
    }

    pair<ll, ll> l[K + 1], u[K + 1];
    // l[i] = (潰されないaの下限値,
    //         a=下限値の場合, 時刻r[i]にてAに入っている砂の量)
    // rは上限

    l[0] = make_pair(0LL, 0LL);
    u[0] = make_pair(X, X);

    for (int i = 1; i <= K; ++i) {
        if (i % 2 > 0) {
            // A->Bへ砂が移る
            ll s = u[i - 1].second - (r[i] - r[i - 1]);
            if (s >= 0) {
                u[i] = make_pair(u[i - 1].first, s);
            } else {
                // aがどれだけ小さくても潰れる
                u[i] = make_pair(0, 0);
                l[i] = make_pair(0, 0);
                continue;
            }

            s = l[i - 1].second - (r[i] - r[i - 1]);
            if (s >= 0) {
                l[i] = make_pair(l[i - 1].first, s);
            } else {
                l[i] = make_pair(l[i - 1].first - s, 0);
            }
        } else {
            // B->Aへ砂が移る
            ll s = l[i - 1].second + (r[i] - r[i - 1]);
            if (s <= X) {
                l[i] = make_pair(l[i - 1].first, s);
            } else {
                // aがどれだけ大きくても潰れる
                l[i] = make_pair(X, X);
                u[i] = make_pair(X, X);
                continue;
            }

            s = u[i - 1].second + (r[i] - r[i - 1]);
            if (s <= X) {
                u[i] = make_pair(u[i - 1].first, s);
            } else {
                u[i] = make_pair(u[i - 1].first - (s - X), X);
            }
        }
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        ll t, a;
        cin >> t >> a;

        // r[i] <= tなる最大のiを探る
        int ok = 0, ng = K + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (r[mid] <= t) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        // 時刻r[i]における砂の量を求める
        ll s = 0;
        if (a < l[ok].first) {
            s = l[ok].second;
        } else if (a > u[ok].first) {
            s = u[ok].second;
        } else {
            s = a - l[ok].first + l[ok].second;
        }

        // 時刻tにおける砂の量を限度無視で求める
        if (ok % 2 == 0) {
            s -= t - r[ok];
        } else {
            s += t - r[ok];
        }

        cout << max(0LL, min(s, X)) << endl;
    }
    return 0;
}
