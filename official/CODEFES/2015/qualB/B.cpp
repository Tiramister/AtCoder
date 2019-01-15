#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int res[M + 1];
    fill(res, res + M + 1, 0);

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ++res[a];
    }

    for (int i = 0; i <= M; ++i) {
        if (res[i] * 2 > N) {
            cout << i << endl;
            return 0;
        }
    }

    cout << '?' << endl;
    return 0;
}
