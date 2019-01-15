#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class BIT {
public:
    explicit BIT(ll N, ll v) : V_NUM(N) {
        data.resize(N);
        fill(data.begin(), data.end(), v);
    }

    ll query(ll i) {
        ll ret = 0;
        while (i > 0) {
            ret = max(ret, data[i]);
            i -= (i & -i);
        }
        return ret;
    }

    void update(ll i, ll v) {
        while (i < V_NUM) {
            data[i] = max(data[i], v);
            i += (i & -i);
        }
    }

    ll V_NUM;
    vector<ll> data;
};

int main() {
    int N;
    cin >> N;

    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    ll a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    BIT bit(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        bit.update(h[i], bit.query(h[i]) + a[i]);
    }

    cout << bit.query(N) << endl;
    return 0;
}
