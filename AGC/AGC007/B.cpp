#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int p[N];
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    int a[N], b[N];

    // a_i + b_iが等しくなるよう初期化
    for (int i = 0; i < N; ++i) {
        a[i] = i * 20000;
    }
    for (int i = 0; i < N; ++i) {
        b[N - i - 1] = i * 20000;
    }

    // pの先頭から加算 indexに注意
    for (int i = 0; i < N; ++i) {
        a[p[i] - 1] += i + 1;
        b[p[i] - 1] += i + 1;
    }

    // 出力
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
