#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll A[N], B[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int ans = 0;
    priority_queue<ll> excess;
    ll lack = 0;

    for (int i = 0; i < N; ++i) {
        ll diff = A[i] - B[i];
        if (diff < 0) {
            lack -= diff;
            ++ans;
        } else {
            excess.push(diff);
        }
    }

    while (!excess.empty() && lack > 0) {
        ll d = excess.top();
        excess.pop();
        lack -= d;
        ++ans;
    }

    cout << (lack <= 0 ? ans : -1) << endl;
    return 0;
}
