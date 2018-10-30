#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int x[N], y[N], h[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i] >> h[i];
    }

    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int ch = 0;
            for (int i = 0; i < N; ++i) {
                if (h[i] > 0) {
                    ch = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
                    break;
                }
            }

            bool judge = true;
            for (int i = 0; i < N; ++i) {
                int preh = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
                if (h[i] == 0 && ch > preh) {
                    judge = false;
                } else if (h[i] > 0 && ch != preh) {
                    judge = false;
                }
            }

            if (judge) {
                cout << cx << " " << cy << " " << ch << endl;
                return 0;
            }
        }
    }
    return 0;
}
