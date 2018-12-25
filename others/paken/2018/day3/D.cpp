#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll sum[N];
    sum[0] = 0;
    for (int i = 1; i < N; ++i) {
        ll c;
        cin >> c;
        sum[i] = sum[i - 1] + c;
    }

    ll mi[N], ma[N];
    mi[0] = 0;
    for (int i = 1; i < N; ++i) {
        mi[i] = min(mi[i - 1], sum[i]);
    }

    ma[N - 1] = sum[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        ma[i] = max(ma[i + 1], sum[i]);
    }

    for (int r = 0; r < N; ++r) {
        cout << max(sum[r] - mi[r], ma[r] - sum[r]) << endl;
    }

    return 0;
}
