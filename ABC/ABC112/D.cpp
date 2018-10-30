#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int ans = 1;
    for (int i = 1; i * i <= M; ++i) {
        if (M % i != 0) continue;
        if (M / i >= N) ans = i;
        if (i >= N) {
            ans = M / i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
