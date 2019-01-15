#include <cmath>
#include <iostream>

using namespace std;

const int INF = 1 << 30;

int main() {
    int N;
    cin >> N;

    int h[N];
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    int cost[N + 1];
    cost[0] = 0, cost[1] = INF;
    for (int i = 0; i < N - 1; ++i) {
        cost[i + 1] = min(cost[i + 1], cost[i] + abs(h[i + 1] - h[i]));
        cost[i + 2] = cost[i] + abs(h[i + 2] - h[i]);
    }

    cout << cost[N - 1] << endl;
    return 0;
}
