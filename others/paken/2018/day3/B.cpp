#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int y = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        y += a;
        if (y <= 2018) ++ans;
    }

    cout << ans << endl;
    return 0;
}
