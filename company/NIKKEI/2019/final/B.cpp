#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    if (N != M) {
        cout << (N < M ? "X" : "Y") << endl;
        return 0;
    }

    vector<int> A(N), B(M);
    for (int& a : A) cin >> a;
    for (int& b : B) cin >> b;
    cout << (A < B ? "X" : (A > B ? "Y" : "Same")) << endl;
    return 0;
}
