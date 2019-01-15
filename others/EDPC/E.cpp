#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;
const int MAX_V = 200000;

ll minw[110][MAX_V + 1];

int main() {
    int N;
    ll W;
    cin >> N >> W;

    fill(minw[0], minw[1], INF);
    minw[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        memcpy(minw[i], minw[i - 1], sizeof(minw[i]));

        ll w;
        int v;
        cin >> w >> v;
        for (int sv = 0; sv + v <= MAX_V; ++sv) {
            minw[i][v + sv] = min(minw[i][v + sv], minw[i - 1][sv] + w);
        }
    }

    for (int v = MAX_V; v >= 0; --v) {
        if (minw[N][v] <= W) {
            cout << v << endl;
            break;
        }
    }
    return 0;
}
