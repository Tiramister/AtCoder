#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int N;
    cin >> N;

    ll sum = 0, minB = INF;
    bool same = true;
    // sum = Aの合計
    // minB = A[i] > B[i]で最小のB[i]

    for (int i = 0; i < N; ++i) {
        ll A, B;
        cin >> A >> B;
        sum += A;
        if (A > B) minB = min(minB, B);
        if (A != B) same = false;
    }

    // 全部同じだったら答えは0であることに注意
    cout << (same ? 0 : sum - minB) << endl;
    return 0;
}
