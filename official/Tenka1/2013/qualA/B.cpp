#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int sum = 0;

        for (int j = 0; j < 5; ++j) {
            int s;
            cin >> s;
            sum += s;
        }

        if (sum < 20) ++ans;
    }

    cout << ans << endl;
    return 0;
}
