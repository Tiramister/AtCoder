#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int t[N + 1], x[N + 1], y[N + 1];
    t[0] = x[0] = y[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> t[i] >> x[i] >> y[i];
    }

    for (int i = 0; i < N; ++i) {
        int dt = t[i + 1] - t[i];
        int dx = x[i + 1] - x[i];
        int dy = y[i + 1] - y[i];

        int dis = abs(dx) + abs(dy);
        if (dis > dt || dt % 2 != dis % 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
