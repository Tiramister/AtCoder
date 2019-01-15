#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 25;

class BIT {
public:
    // 要素数N、値vで初期化
    explicit BIT(int N, int v) : V_NUM(N) {
        data.resize(N);
        fill(data.begin(), data.end(), v);
    }

    // [1, i]の総和を求める
    int query(int i) {
        int ret = 0;
        while (i > 0) {
            ret += data[i];
            i -= (i & -i);
        }
        return ret;
    }

    // data[i]にv可算
    void update(int i, int v) {
        while (i < V_NUM) {
            data[i] += v;
            i += (i & -i);
        }
    }

    int V_NUM;
    vector<int> data;
};

int main() {
    int N;
    cin >> N;

    int a[N * 2];
    char c[N * 2];
    for (int i = 0; i < N * 2; ++i) {
        cin >> c[i] >> a[i];
    }

    int ww[N + 1], bb[N + 1];
    ww[0] = bb[0] = 0;
    // ww[i] = 白iより手前にある白i+xの数(x > 0)

    int wb[N + 1][N + 1], bw[N + 1][N + 1];
    fill(wb[0], wb[0] + N + 1, 0);
    fill(bw[0], bw[0] + N + 1, 0);
    // wb[i][j] = 白iより手前にある黒j+xの数(x > 0)

    BIT white(N + 1, 0), black(N + 1, 0);
    // white[i] = 白i以下がいくつ出てきたか

    for (int i = 0; i < N * 2; ++i) {
        if (c[i] == 'W') {
            ww[a[i]] = white.query(N) - white.query(a[i]);
            wb[a[i]][0] = black.query(N);
            for (int j = 1; j <= N; ++j) {
                wb[a[i]][j] = black.query(N) - black.query(j);
            }
            white.update(a[i], 1);
        } else {
            bb[a[i]] = black.query(N) - black.query(a[i]);
            bw[a[i]][0] = white.query(N);
            for (int j = 1; j <= N; ++j) {
                bw[a[i]][j] = white.query(N) - white.query(j);
            }
            black.update(a[i], 1);
        }
    }

    int dp[N + 1][N + 1];
    fill(dp[0], dp[N + 1], INF);
    dp[0][0] = 0;
    // dp[w][b] = 白i、黒jを並べる最小コスト

    for (int w = 0; w <= N; ++w) {
        for (int b = 0; b <= N; ++b) {
            if (w < N) dp[w + 1][b] = min(dp[w + 1][b], dp[w][b] + ww[w + 1] + wb[w + 1][b]);
            if (b < N) dp[w][b + 1] = min(dp[w][b + 1], dp[w][b] + bb[b + 1] + bw[b + 1][w]);
        }
    }

    cout << dp[N][N] << endl;
    return 0;
}
