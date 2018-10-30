#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum ^= a[i];
        a[i] &= -a[i];
    }

    int ans = 0;
    for (int b = 30; b >= 0; --b) {
        if (((sum >> b) & 1) == 0) continue;
        for (int i = 0; i < N; ++i) {
            if (((a[i] >> b) & 1) == 1) {
                ++ans;
                sum ^= (a[i] << 1) - 1;
                break;
            }
        }
    }

    cout << (sum > 0 ? -1 : ans) << endl;
    return 0;
}
