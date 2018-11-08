#include <iostream>

using namespace std;

const int MAX_V = 1000000;
int cnt[MAX_V + 10];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int s;
        cin >> s;
        ++cnt[s];
    }

    for (int i = 1; i <= MAX_V; ++i) {
        cnt[i] += cnt[i - 1];
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int k;
        cin >> k;
        if (k >= N - cnt[0]) {
            cout << 0 << endl;
            continue;
        }

        int ok = MAX_V + 1, ng = 0;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (N - cnt[mid - 1] <= k) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        cout << ok << endl;
    }
    return 0;
}
