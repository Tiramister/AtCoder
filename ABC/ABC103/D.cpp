#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    pair<int, int> segs[M];
    for (int i = 0; i < M; i++) {
        cin >> segs[i].second >> segs[i].first;
    }

    sort(segs, segs + M);

    int ans = 0, trim = -1;
    for (int i = 0; i < M; i++) {
        if (segs[i].second > trim) {
            ans++;
            trim = segs[i].first - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
