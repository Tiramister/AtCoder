#include <iostream>
using namespace std;
using ll = long long;

int N, K;
int A[100010];
ll B[100010];

ll buy(ll L) {
    ll val = 0;
    for (int i = 0; i < N; ++i) {
        if ((L & A[i]) == A[i]) {
            val += B[i];
        }
    }

    return val;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    ll ans = buy(K);
    for (int b = 0; b < 30; ++b) {
        if ((K >> b) & 1) {
            ll L = (K ^ (1 << b));
            L |= (1 << b) - 1;
            ans = max(ans, buy(L));
        }
    }

    cout << ans << endl;
    return 0;
}
