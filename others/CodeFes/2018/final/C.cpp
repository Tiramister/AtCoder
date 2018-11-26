#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int N;
    cin >> N;

    pair<ll, ll> p[N + 2];
    for (int i = 1; i <= N; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    // 番兵的なやつ
    p[0] = make_pair(0, INF);
    p[N + 1] = make_pair(INF, INF);
    sort(p, p + N + 2);

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        ll t;
        cin >> t;

        // p[ok].first <= tなるokをにぶたん
        int ok = 0, ng = N + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (p[mid].first <= t) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        ll ans = min(p[ok].second + (t - p[ok].first), p[ok + 1].second);
        cout << ans << endl;
    }
    return 0;
}
