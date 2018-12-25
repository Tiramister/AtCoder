#include <cmath>
#include <iostream>

using namespace std;

bool inarea(double x, double y) {
    return abs(x) + abs(y) <= 1;
}

int main() {
    int N;
    cin >> N;

    bool in[N + 1][N + 1];
    for (int x = 0; x <= N; ++x) {
        for (int y = 0; y <= N; ++y) {
            in[x][y] = inarea(x * 2.0 / N - 1, y * 2.0 / N - 1);
        }
    }

    int ans = 0;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            ans += in[x][y] && in[x + 1][y] && in[x][y + 1] && in[x + 1][y + 1];
        }
    }

    cout << ans << endl;
    return 0;
}
