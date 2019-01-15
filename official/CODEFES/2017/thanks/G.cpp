#include <iostream>
using namespace std;


int pcnt(int b) {
    return __builtin_popcountll(b);
}


int main() {
    int N, M;
    cin >> N >> M;
    int a[M], b[M];
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    // 要素を[0, half)と[half, N)に分ける
    int half = N / 2;
    int n = N - half;

    // 前半分の独立部分集合か判定する配列
    bool fok[1 << half];
    fill(fok, fok + (1 << half), true);
    for (int i = 0; i < M; ++i) {
        if (b[i] < half) {
            fok[(1 << a[i]) + (1 << b[i])] = false;
        }
    }

    for (int b = 0; b < (1 << half); ++b) {
        for (int i = 0; i < half; ++i) {
            if ((b >> i) & 1) {
                fok[b] &= fok[b ^ (1 << i)];
            }
        }
    }


    // 前半分を決めたとき, 選ぶことができる後半分の集合
    int match[1 << half];
    fill(match, match + (1 << half), (1 << n) - 1);
    for (int i = 0; i < M; ++i) {
        if (a[i] < half && half <= b[i]) {
            match[1 << a[i]] ^= (1 << (b[i] - half));
        }
    }

    for (int b = 0; b < (1 << half); ++b) {
        for (int i = 0; i < half; ++i) {
            if ((b >> i) & 1) {
                match[b] &= match[b ^ (1 << i)];
            }
        }
    }


    // 後半分の独立部分集合か判定する配列
    bool bok[1 << n];
    fill(bok, bok + (1 << n), true);
    for (int i = 0; i < M; ++i) {
        if (half <= a[i]) {
            bok[(1 << (a[i] - half)) + (1 << (b[i] - half))] = false;
        }
    }

    for (int b = 0; b < (1 << n); ++b) {
        for (int i = 0; i < n; ++i) {
            if ((b >> i) & 1) {
                bok[b] &= bok[b ^ (1 << i)];
            }
        }
    }


    // 後半分の集合から最適な選択をしたときの要素数
    int back[1 << n];
    for (int b = 0; b < (1 << n); ++b) {
        back[b] = (bok[b] ? pcnt(b) : 0);
        for (int i = 0; i < n; ++i) {
            if ((b >> i) & 1) {
                back[b] = max(back[b], back[b ^ (1 << i)]);
            }
        }
    }


    int ans = 0;
    for (int b = 0; b < (1 << half); ++b) {
        if (fok[b]) {
            ans = max(ans, pcnt(b) + back[match[b]]);
        }
    }

    cout << ans << endl;
    return 0;
}
