#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    ll place[N + 1];
    for (int i = 1; i <= N; ++i) {
        ll a;
        cin >> a;
        place[a] = i;
    }

    ll ans = 0;
    set<ll> used = {0, N + 1};
    for (int i = 1; i <= N; ++i) {
        ll r, l;
        auto itr = used.lower_bound(place[i]);
        r = *itr;
        l = *(--itr);
        ans += i * (place[i] - l) * (r - place[i]);
        used.insert(place[i]);
    }

    cout << ans << endl;
    return 0;
}
