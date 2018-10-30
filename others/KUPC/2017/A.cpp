#include <algorithm>
#include <iostream>
using namespace std;

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())

int main() {
    int N, K;
    cin >> N >> K;

    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    gsort(a, a + N);

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += a[i];
        if (sum >= K) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
