#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    long double ans = -1;
    vector<int> ice = {0};
    int cnt = 0;

    for (char c : S) {
        if (c == '-') {
            if (cnt > 0) ice.push_back(cnt);
            cnt = 0;
            ans += 1;
        } else {
            ++cnt;
        }
    }

    sort(ice.rbegin(), ice.rend());
    ++ice.front();
    for (int l : ice) {
        for (int i = 0; i < l; ++i) {
            ans += 1.0 / (i + 2);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
