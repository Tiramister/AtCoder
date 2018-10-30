#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const double EPS = 1e-10;

int main() {
    cout << fixed << setprecision(10);

    int K;
    cin >> K;

    double R[1 << K];
    double pro[1 << (K + 1)][1 << K];
    fill(pro[0], pro[1 << (K + 1)], 0);
    // pro[i][j] = i番の試合にjが来る確率

    for (int i = 0; i < (1 << K); ++i) {
        cin >> R[i];
        pro[(1 << K) + i][i] = 1;
    }

    for (int i = (1 << K) - 1; i > 0; --i) {
        for (int j = 0; j < (1 << K); ++j) {
            if (pro[i * 2][j] < EPS) continue;

            for (int k = 0; k < (1 << K); ++k) {
                if (pro[i * 2 + 1][k] < EPS) continue;

                // jとkがマッチングする確率
                double p = pro[i * 2][j] * pro[i * 2 + 1][k];

                // jが勝つ確率
                double q = 1 / (1 + pow(10, (R[k] - R[j]) / 400));

                pro[i][j] += p * q;
                pro[i][k] += p * (1 - q);
            }
        }
    }

    for (int i = 0; i < (1 << K); ++i) {
        cout << pro[1][i] << endl;
    }

    return 0;
}
