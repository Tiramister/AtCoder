#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        ll A, B;
        cin >> A >> B;
        ll L = B - A + 1;

        vector<pair<ll, ll>> segs;

        for (ll k = 1; k <= L; ++k) {
            ll sum = A * k;

            ll fore = k * (k - 1) / 2;
            ll back = fore + (L - k) * k;

            segs.push_back(make_pair(sum + fore, sum + back));
        }

        ll R = 0, ans = 0;
        for (auto p : segs) {
            if (R < p.first) {
                ans += p.second - p.first + 1;
            } else if (R >= p.second) {
                continue;
            } else {
                ans += p.second - R;
            }
            R = p.second;
            ans %= MOD;
        }

        cout << ans << endl;
    }
    return 0;
}
