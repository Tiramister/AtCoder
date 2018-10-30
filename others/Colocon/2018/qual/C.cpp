#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

ll rec(ll id, ll end, vector<ll>& used) {
    if (id == end) {
        return 1;
    }

    ll ret = rec(id + 1, end, used);
    for (ll i : used) {
        if (gcd(i, id) > 1) {
            return ret;
        }
    }

    used.push_back(id);
    ret += rec(id + 1, end, used);
    used.pop_back();
    return ret;
}

int main() {
    ll A, B;
    cin >> A >> B;
    vector<ll> used;
    cout << rec(A, B + 1, used) << endl;
    return 0;
}
