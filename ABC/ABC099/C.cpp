#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = N;
    for (int s = 0; s <= N; ++s) {
        // s円を6^nで払う
        // N - s円を9^nで払う
        int cnt = 0;

        int ns = s;
        while (ns > 0) {
            cnt += ns % 6;
            ns /= 6;
        }

        ns = N - s;
        while (ns > 0) {
            cnt += ns % 9;
            ns /= 9;
        }

        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
