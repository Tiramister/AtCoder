#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    ll sum[N + 1];
    sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        ll a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }

    vector<ll> S;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            S.push_back(sum[j] - sum[i]);
        }
    }

    ll ans = 0;

    while (!S.empty()) {
        vector<ll> nums[50];
        for (ll n : S) {
            for (int k = 49; k >= 0; --k) {
                if (n & (1LL << k)) {
                    nums[k].push_back(n);
                }
            }
        }

        S.clear();

        for (int k = 49; k >= 0; --k) {
            if (nums[k].size() >= K) {
                ans |= (1LL << k);
                for (ll n : nums[k]) {
                    S.push_back(n ^ (1LL << k));
                }
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
