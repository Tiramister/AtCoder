#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int n;
    for (n = 0; n * (n + 1) / 2 < N; ++n) {};

    if (n * (n + 1) / 2 != N) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << n + 1 << endl;

    vector<int> ans[n + 1];

    int base = 1;
    for (int i = 0; i < n; ++i) {
        // n - i個の集合
        // [base, base + n - i)を埋める
        for (int j = 0; j < n - i; ++j) {
            ans[i].push_back(j + base);
            ans[i + j + 1].push_back(j + base);
        }

        base += n - i;
    }

    for (int i = 0; i < n + 1; ++i) {
        cout << ans[i].size() << " ";
        for (int c : ans[i]) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
