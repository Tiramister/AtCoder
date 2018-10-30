#include <iostream>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    int ans = 10000;
    for (int i = 0; i < N; ++i) {
        int c, t;
        cin >> c >> t;
        if (t <= T) ans = min(ans, c);
    }

    if (ans == 10000) {
        cout << "TLE" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
