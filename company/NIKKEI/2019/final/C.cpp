#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll H, W;
    int K;
    cin >> H >> W >> K;
    ll h[H + 1], w[W + 1];
    fill(h, h + H + 1, W);
    fill(w, w + W + 1, H);
    for (int i = 0; i < K; ++i) {
        int R, C;
        cin >> R >> C;
        --h[R];
        --w[C];
    }

    ll hsum[H + 1], wsum[W + 1];
    hsum[0] = wsum[0] = 0;
    for (int i = 1; i <= H; ++i) hsum[i] = hsum[i - 1] + h[i];
    for (int j = 1; j <= W; ++j) wsum[j] = wsum[j - 1] + w[j];

    ll ans = 0;
    ll hc = upper_bound(hsum, hsum + H + 1, (H * W - K) / 2) - hsum;
    for (ll i = 1; i <= H; ++i) ans += abs(hc - i) * h[i];
    ll wc = upper_bound(wsum, wsum + W + 1, (H * W - K) / 2) - wsum;
    for (ll j = 1; j <= W; ++j) ans += abs(wc - j) * w[j];

    cout << ans << endl;
    return 0;
}
