#include <iostream>
using namespace std;
const int INF = 1 << 30;

int main() {
    const int R = 12 * 60 * 60;

    int H, M, S;
    cin >> H >> M >> S;

    int MS, HM;
    cin >> MS >> HM;

    int h = H * 60 * 60 + M * 60 + S;
    int m = h * 12;
    int s = m * 60;
    MS += (s - m) / R;
    HM += (m - h) / R;

    int mi = INF, ma = 0;
    for (int t = 1; t < 1e8; ++t) {
        h += 1;
        m += 12;
        s += 12 * 60;
        if ((s - m) % R == 0 || (m - h) % R == 0) continue;
        if ((s - m) / R > MS || (m - h) / R > HM) break;

        if ((s - m) / R == MS && (m - h) / R == HM) {
            mi = min(mi, t);
            ma = max(ma, t);
        }
    }

    if (mi == INF) {
        cout << -1 << endl;
    } else {
        cout << mi << " " << ma << endl;
    }
    return 0;
}
