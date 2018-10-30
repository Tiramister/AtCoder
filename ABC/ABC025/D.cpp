#include <iostream>
#include <map>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

bool on(ll bit, int idx) {
    return (bit >> idx) & 1;
}

bool judge(int stat, int pos) {
    bool ret = true;
    if (pos % 5 > 0 && pos % 5 < 4 && on(stat, pos - 1) != on(stat, pos + 1)) ret = false;

    if (pos > 4 && pos < 20 && on(stat, pos - 5) != on(stat, pos + 5)) ret = false;

    return ret;
}

int dp[1 << 25];
int table[26];

int rec(int stat) {
    if (dp[stat] >= 0) return dp[stat];

    dp[stat] = 0;
    int n = pcnt(stat);
    if (table[n] >= 0) {
        int pos = table[n];
        if (on(stat, pos) && judge(stat, pos)) {
            dp[stat] += rec(stat ^ (1 << pos));
        }
        return dp[stat];
    }

    for (int i = 0; i < 25; ++i) {
        if (on(stat, i) && judge(stat, i)) {
            dp[stat] += rec(stat ^ (1 << i));
            dp[stat] %= MOD;
        }
    }
    return dp[stat];
}

int main() {
    fill(dp, dp + (1 << 25), -1);
    fill(table, table + 26, -1);

    dp[0] = 1;
    for (int i = 0; i < 25; ++i) {
        int x;
        cin >> x;
        if (x > 0) table[x] = i;
    }

    cout << rec((1 << 25) - 1) << endl;
    return 0;
}
