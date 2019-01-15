#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int s[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }
    s[N] = 0;
    sort(s, s + N, greater<int>());

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int k;
        cin >> k;
        cout << s[k] + (s[k] > 0) << endl;
    }

    return 0;
}
