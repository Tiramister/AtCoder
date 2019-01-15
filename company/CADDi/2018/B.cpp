#include <iostream>

using namespace std;

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        ans += (A >= H) && (B >= W);
    }

    cout << ans << endl;
    return 0;
}
