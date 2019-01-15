#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (abs(sum - a[i] * N) < abs(sum - a[ans] * N)) ans = i;
    }

    cout << ans << endl;
    return 0;
}
