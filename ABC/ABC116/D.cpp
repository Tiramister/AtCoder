#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    priority_queue<ll> kind[N];
    for (int i = 0; i < N; ++i) {
        int t;
        ll d;
        cin >> t >> d;
        kind[t - 1].push(d);
    }

    priority_queue<ll> best, remain;
    // best: 各種類で一番美味しいやつを集めたもの
    // remain : bestの余り
    for (int i = 0; i < N; ++i) {
        if (!kind[i].empty()) {
            best.push(kind[i].top());
            kind[i].pop();

            while (!kind[i].empty()) {
                remain.push(kind[i].top());
                kind[i].pop();
            }
        }
    }

    vector<ll> bsum = {0};
    // bestの累積和
    while (!best.empty()) {
        bsum.push_back(bsum.back() + best.top());
        best.pop();
    }

    vector<ll> rsum = {0};
    // remainの累積和
    while (!remain.empty()) {
        rsum.push_back(rsum.back() + remain.top());
        remain.pop();
    }

    ll ans = 0;
    for (ll x = 1; x <= K; ++x) {
        // x種類選んだときの美味しさ

        // 種類が多すぎるケース
        if (x >= bsum.size()) break;

        // 種類が少なすぎて、余り物が足りないケース
        if (K - x >= rsum.size()) continue;

        ans = max(ans, bsum[x] + rsum[K - x] + x * x);
    }

    cout << ans << endl;
    return 0;
}
