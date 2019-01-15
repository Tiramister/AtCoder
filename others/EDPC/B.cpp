#include <cmath>
#include <iostream>

using namespace std;

const int INF = 1 << 30;

int main() {
    int N, K;
    cin >> N >> K;

    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    int cost[N + K];
    fill(cost, cost + N + K, INF);
    cost[0] = 0;

    for (int i = 0; i < N - 1; ++i) {
        for (int k = 1; k <= K; ++k) {
            cost[i + k] = min(cost[i + k], cost[i] + abs(h[i + k] - h[i]));
        }
    }

    cout << cost[N - 1] << endl;
    return 0;
}
