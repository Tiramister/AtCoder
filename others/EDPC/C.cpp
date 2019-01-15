#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int happy[N][3];
    for (int i = 0; i < 3; ++i) {
        cin >> happy[0][i];
    }

    for (int d = 1; d < N; ++d) {
        fill(happy[d], happy[d + 1], 0);
        for (int i = 0; i < 3; ++i) {
            int h;
            cin >> h;
            for (int j = 1; j < 3; ++j) {
                happy[d][i] = max(happy[d][i], happy[d - 1][(i + j) % 3] + h);
            }
        }
    }

    cout << *max_element(happy[N - 1], happy[N]) << endl;
    return 0;
}
