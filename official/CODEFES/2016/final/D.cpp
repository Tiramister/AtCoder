#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1 << 25;

int count_pair(vector<int> v) {
    v.push_back(INF);
    sort(v.begin(), v.end());

    int ret = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] != v[i + 1]) continue;
        ++ret;
        ++i;
    }

    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> card[M];
    for (int i = 0; i < N; ++i) {
        int X;
        cin >> X;
        card[X % M].push_back(X);
    }

    int ans = card[0].size() / 2;
    if (M % 2 == 0) ans += card[M / 2].size() / 2;
    for (int i = 1; i < (M + 1) / 2; ++i) {
        int p = min(card[i].size(), card[M - i].size());
        ans += p;

        int s = count_pair(card[i]);
        ans += min(s, ((int)card[i].size() - p) / 2);
        s = count_pair(card[M - i]);
        ans += min(s, ((int)card[M - i].size() - p) / 2);
    }

    cout << ans << endl;
    return 0;
}
