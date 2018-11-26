#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int r[M];
    for (int i = 0; i < M; ++i) {
        cin >> r[i];
    }

    double p = 0;

    // 1/N!
    for (int n = 1; n <= N; ++n) {
        p -= log10(n);
    }

    // N^M
    p += N * log10(M);

    for (int i = 0; i < M; ++i) {
        // r[i]!
        for (int n = 1; n <= r[i]; ++n) {
            p += log10(n);
        }
    }

    // 雑に切り上げ
    cout << (int)(p + 1) << endl;
    return 0;
}
