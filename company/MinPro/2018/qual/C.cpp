#include <iostream>
using namespace std;
using ll = long long;

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

const ll INF = 1LL << 60;
ll x[18], c[18], v[18];

ll money[20];
ll need[1 << 18], val[1 << 18];
ll dp[1 << 18][20];
ll res[1 << 18];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    // money[k] = k個売ったときの所持金
    money[0] = 0;
    for (int i = 0; i < N; ++i) {
        money[i + 1] = money[i] + x[i];
    }

    // need[S] = Sを全てを買うのに必要な金額
    // val[S] = Sに含まれる商品の価値の合計
    for (int S = 0; S < (1 << N); ++S) {
        need[S] = val[S] = 0;

        for (int i = 0; i < N; ++i) {
            if ((S >> i) & 1) {
                need[S] += c[i];
                val[S] += v[i];
            }
        }
    }

    // dp[S][k]を埋める
    // dp[S][k] = Sが販売されている状態でk個売却済みだったときの最適解
    for (int S = 0; S < (1 << N); ++S) {
        for (int k = 0; k <= N; ++k) {
            if (money[k] >= need[S]) {
                dp[S][k] = val[S];

            } else {
                dp[S][k] = 0;

                // 最適解にて買わないやつを全探索
                for (int i = 0; i < N; ++i) {
                    if ((S >> i) & 1) {
                        dp[S][k] = max(dp[S][k], dp[S ^ (1 << i)][k]);
                    }
                }
            }
        }
    }

    // res[S]を埋める
    // res[S] = Sが販売されている状態での解
    // Sからの遷移先も全て含まれることに注意
    res[0] = 0;

    for (int S = 1; S < (1 << N); ++S) {
        // まだ売る場合
        // このとき青木君はres[S]が最小になるようにしてくる
        ll sell = INF;
        for (int i = 0; i < N; ++i) {
            if ((S >> i) & 1) {
                sell = min(sell, res[S ^ (1 << i)]);
            }
        }

        // ここで買い取りに移る場合
        int k = N - pcnt(S);
        res[S] = max(dp[S][k], sell);
    }

    cout << res[(1 << N) - 1] << endl;
    return 0;
}
