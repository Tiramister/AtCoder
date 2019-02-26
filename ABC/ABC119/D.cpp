#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;

    set<ll> s = {-INF, INF}, t = {-INF, INF};
    for (int i = 0; i < A; ++i) {
        ll a;
        cin >> a;
        s.insert(a);
    }
    for (int i = 0; i < B; ++i) {
        ll a;
        cin >> a;
        t.insert(a);
    }

    for (int q = 0; q < Q; ++q) {
        ll x;
        cin >> x;
        auto sitr = s.upper_bound(x);
        ll sr = *sitr, sl = *(--sitr);
        auto titr = t.upper_bound(x);
        ll tr = *titr, tl = *(--titr);

        cout << min({
                    min(sr - x, x - tl) + (sr - tl),
                    min(tr - x, x - sl) + (tr - sl),
                    max(sr, tr) - x,
                    x - min(sl, tl),
                })
             << endl;
    }
    return 0;
}
