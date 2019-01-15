#include <iostream>
#include <map>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    map<int, int> coo;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        coo[a] = 1;
    }
    for (int i = 0; i < N; ++i) {
        int b;
        cin >> b;
        coo[b] = -1;
    }

    ll ans = 1;
    ll cnt = 0;
    for (auto p : coo) {
        ll k = p.second;
        if (cnt * k < 0) {
            ans *= abs(cnt);
            ans %= MOD;
        }
        cnt += k;
    }

    cout << ans << endl;
    return 0;
}
