#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

int main() {
    int N;
    cin >> N;

    ll u[N], v[N];
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        u[i] = x + y;
        v[i] = x - y;
    }

    ll minu = *min_element(u, u + N);
    ll maxu = *max_element(u, u + N);
    ll minv = *min_element(v, v + N);
    ll maxv = *max_element(v, v + N);

    ll r = iceil(max(maxu - minu, maxv - minv), 2LL);

    ll cu[2] = {minu + r, maxu - r};
    ll cv[2] = {minv + r, maxv - r};

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            bool judge = true;
            for (int k = 0; k < N; ++k) {
                if (max(abs(u[k] - cu[i]), abs(v[k] - cv[j])) != r) judge = false;
            }

            if (judge) {
                cout << (cu[i] + cv[j]) / 2 << " " << (cu[i] - cv[j]) / 2 << endl;
                return 0;
            }
        }
    }
    return 0;
}
