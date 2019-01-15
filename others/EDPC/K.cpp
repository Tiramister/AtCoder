#include <iostream>

using namespace std;

int N, a[100];
bool memo[100010], visited[100010];

bool rec(int K) {
    if (visited[K]) return memo[K];

    visited[K] = true;
    memo[K] = false;

    for (int i = 0; i < N; ++i) {
        if (a[i] > K) break;
        if (!rec(K - a[i])) {
            memo[K] = true;
            break;
        }
    }

    return memo[K];
}

int main() {
    int K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    cout << (rec(K) ? "First" : "Second") << endl;
    return 0;
}
