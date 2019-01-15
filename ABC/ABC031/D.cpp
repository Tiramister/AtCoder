#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

vector<int> decode(int t, int K) {
    vector<int> ret(K);
    for (int i = 0; i < K; ++i) {
        ret[i] = t % 3 + 1;
        t /= 3;
    }
    return ret;
}

int main() {
    int K, N;
    cin >> K >> N;

    string v[N], w[N];
    for (int i = 0; i < N; ++i) {
        cin >> v[i] >> w[i];
    }

    for (int t = 0; t < mypow(3, K); ++t) {
        vector<int> l = decode(t, K);

        bool judge = true;

        for (int i = 0; i < N; ++i) {
            int len = 0;
            for (char c : v[i]) {
                len += l[c - '1'];
            }
            if (len != w[i].length()) judge = false;
        }
        if (!judge) continue;

        string pat[K];
        for (int i = 0; i < N; ++i) {
            int pos = 0;
            for (char c : v[i]) {
                pat[c - '1'] = w[i].substr(pos, l[c - '1']);
                pos += l[c - '1'];
            }
        }

        for (int i = 0; i < N; ++i) {
            string W = "";
            for (char c : v[i]) {
                W += pat[c - '1'];
            }

            if (W != w[i]) judge = false;
        }

        if (!judge) continue;
        for (int i = 0; i < K; ++i) {
            cout << pat[i] << endl;
        }
        return 0;
    }
    return 0;
}
