#include <iomanip>
#include <iostream>

using namespace std;
using ld = long double;

int main() {
    int N;
    cin >> N;

    ld ans = 0;
    for (int i = 0; i < N; ++i) {
        ld x;
        string u;
        cin >> x >> u;
        ans += x * (u == "JPY" ? 1 : 380000);
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
