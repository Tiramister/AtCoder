#include <iostream>
using namespace std;

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        X = max(X, x);
    }

    for (int i = 0; i < M; ++i) {
        int y;
        cin >> y;
        Y = min(Y, y);
    }

    if (X < Y) {
        cout << "No ";
    }
    cout << "War" << endl;
    return 0;
}
