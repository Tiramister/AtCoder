#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    if (N < A + B - 1 || A * B < N) {
        cout << -1 << endl;
        return 0;
    }

    ll arr[A];
    fill(arr, arr + A, 1);
    arr[0] = B;
    N -= A + B - 1;

    for (ll i = 1; i < A; ++i) {
        arr[i] += min(N, B - 1);
        N -= min(N, B - 1);
    }

    ll used = 0;
    for (ll i = 0; i < A; ++i) {
        used += arr[i];
        for (ll j = 0; j < arr[i]; ++j) {
            cout << used - j << " ";
        }
    }
    cout << endl;
    return 0;
}
