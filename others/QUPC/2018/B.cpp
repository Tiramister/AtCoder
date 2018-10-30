#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        ll A, B, C;
        cin >> A >> B >> C;

        ll sum = A * 100 + B * 10 + C;
        if (sum % 2 > 0) {
            cout << "No" << endl;
            continue;
        }

        sum /= 2;

        sum -= min(sum / 100, A) * 100;
        sum -= min(sum / 10, B) * 10;
        sum -= min(sum, C);

        cout << (sum == 0 ? "Yes" : "No") << endl;
    }
    return 0;
}
