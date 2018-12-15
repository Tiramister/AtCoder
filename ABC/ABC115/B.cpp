#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0, pmax = 0;
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        sum += p;
        pmax = max(pmax, p);
    }

    cout << sum - pmax / 2 << endl;
    return 0;
}
