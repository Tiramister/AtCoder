#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int N;
    double T, A;
    cin >> N >> T >> A;

    // (平均気温とTの差, index)の配列
    pair<double, int> t[N];
    for (int i = 0; i < N; ++i) {
        double H;
        cin >> H;
        double diff = abs(A - (T - H * 0.006));

        // indexは1-indexedで保持
        t[i] = make_pair(diff, i + 1);
    }

    // pairをソートすると、第一要素が優先的にソートされる
    sort(t, t + N);
    cout << t[0].second << endl;
    return 0;
}
