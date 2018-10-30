#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int L[N * 2];
    for (int i = 0; i < N * 2; ++i) {
        cin >> L[i];
    }

    sort(L, L + N * 2);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        // L[2i]とL[2i+1]を組み合わせる
        ans += L[i * 2];
    }

    cout << ans << endl;
    return 0;
}
