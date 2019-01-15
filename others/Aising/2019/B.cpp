#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        if (p <= A) {
            ++cnt[0];
        } else if (p <= B) {
            ++cnt[1];
        } else {
            ++cnt[2];
        }
    }
    cout << min({cnt[0], cnt[1], cnt[2]}) << endl;
    return 0;
}
