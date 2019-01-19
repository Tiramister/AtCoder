#include <iostream>
#include <deque>

using namespace std;
using ll = long long;

int K;

deque<int> rec(int l, int r, ll R) {
    int N = r - l + 1;
    if (N == 0 && R > 0) return deque<int>();

    deque<int> ret;

    if (R == 0) {
        // 昇順におくだけ
        for (int i = l; i <= r; ++i) {
            ret.push_back(i);
        }
        return ret;
    }

    // lを右端に置けば、[l+K, r]の分が確実に加算される
    int gain = r - (l + K) + 1;

    if (R >= gain) {
        // lを右端に置いてRを削る
        ret = rec(l + 1, r, R - gain);
        if (!ret.empty()) ret.push_back(l);
    } else if (R > 0) {
        // lを左端に置き、gainがRになるまで減らす
        ret = rec(l + 1, r, R);
        if (!ret.empty()) ret.push_front(l);
    }

    return ret;
}

int main() {
    ll N, R;
    cin >> N >> K >> R;

    auto res = rec(1, N, R);

    if (res.empty()) {
        cout << "No Luck" << endl;
    } else {
        for (int i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
