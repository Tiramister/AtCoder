#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<ll, int>> cut[N + 1];
    // cut[Li]=(Ti, Ri)

    for (int i = 0; i < M; ++i) {
        ll T;
        int L, R;
        cin >> T >> L >> R;
        cut[L].push_back(make_pair(T, R));
    }

    ll ans = 0;
    priority_queue<pair<ll, int>> que;
    que.push(make_pair(0, N));  // 最初に空振りを入れる

    for (int i = 1; i <= N; ++i) {
        for (auto p : cut[i]) que.push(p);
        ans += que.top().first;
        while (!que.empty() && que.top().second <= i) que.pop();
    }

    cout << ans << endl;
    return 0;
}
