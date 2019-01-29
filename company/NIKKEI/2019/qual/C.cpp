#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    pair<ll, ll> dish[N];
    for (int i = 0; i < N; ++i) {
        cin >> dish[i].first >> dish[i].second;
    }

    // 和について降順にソート
    sort(dish, dish + N, [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.first + a.second > b.first + b.second;
    });

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            ans += dish[i].first;
        } else {
            ans -= dish[i].second;
        }
    }

    cout << ans << endl;
    return 0;
}
