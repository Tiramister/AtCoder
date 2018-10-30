#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())

template <typename T>
T sq(T a) {
    return a * a;
}

int main() {
    double x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }

    // (x[0], y[0])を原点に平行移動
    for (int i = 2; i >= 0; --i) {
        x[i] -= x[0];
        y[i] -= y[0];
    }

    // 三角形の面積
    double S = abs(x[1] * y[2] - x[2] * y[1]) / 2;

    // 各辺の長さ
    double r[3];
    for (int i = 0; i < 3; ++i) {
        r[i] = sqrt(sq(x[i] - x[(i + 1) % 3]) + sq(y[i] - y[(i + 1) % 3]));
    }

    // 内接円の半径
    double z = S * 2 / (r[0] + r[1] + r[2]);
    gsort(r, r + 3);

    double ok = 0, ng = 1000;
    for (int i = 0; i < 100; ++i) {
        double mid = (ok + ng) / 2;
        if (mid * 2 <= r[0] * (1 - mid / z)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << fixed << setprecision(15) << ok << endl;
    return 0;
}
