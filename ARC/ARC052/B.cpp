#include <iomanip>
#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>

using namespace std;
using ld = long double;

const ld PI = acos(-1);

template <typename T>
inline T sq(T a) { return a * a; }

template <typename T>
inline T tri(T a) { return a * a * a; }

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<ld, int>> corn[10001];
    for (int i = 0; i < N; ++i) {
        int x, h;
        ld r;
        cin >> x >> r >> h;
        corn[x].push_back(make_pair(r, h));
    }

    ld sum[10001];
    sum[0] = 0;
    for (int x = 0; x < 10000; ++x) {
        sum[x + 1] = sum[x];
        while (!corn[x].empty()) {
            ld r;
            int h;
            tie(r, h) = corn[x].back();
            corn[x].pop_back();
            sum[x + 1] += PI * sq(r) * ld(h) * (1 - tri(ld(h - 1) / h)) / 3;
            if (h > 1) {
                corn[x + 1].push_back(make_pair(r * (h - 1) / h, h - 1));
            }
        }
    }

    for (int q = 0; q < Q; ++q) {
        int a, b;
        cin >> a >> b;
        cout << fixed << setprecision(10) << sum[b] - sum[a] << endl;
    }
    return 0;
}
