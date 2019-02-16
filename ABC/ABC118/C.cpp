#include <iostream>

using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ans = gcd(ans, a);
    }

    cout << ans << endl;
    return 0;
}
