#include <iostream>

using namespace std;

int main() {
    int T, A, B, C, D;
    cin >> T >> A >> B >> C >> D;

    int ans = 0;
    if (T >= C) {
        ans += D;
        T -= C;
    }

    if (T >= A) ans += B;

    cout << ans << endl;
    return 0;
}
