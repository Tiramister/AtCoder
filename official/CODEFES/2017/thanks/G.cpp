#include <iostream>
#include <vector>
#include <map>

using namespace std;

class MaximumIndependentSet {
    using ll = long long;

public:
    int V_NUM;
    vector<vector<int>> path;
    map<ll, int> dp;

    explicit MaximumIndependentSet(int V_NUM) : V_NUM(V_NUM) {
        path.resize(V_NUM);
        dp[0] = 0;
    }

    void connect(int x, int y) {
        if (x > y) swap(x, y);
        path[x].push_back(y);
    }

    int lowbit(ll S) {
        int l;
        for (l = 0; l < V_NUM; ++l) {
            if ((S >> l) & 1) break;
        }
        return l;
    }

    int rec(ll S) {
        if (dp.count(S)) return dp[S];
        int& ret = dp[S];

        int l = lowbit(S);
        S ^= (1LL << l);

        ret = rec(S);

        for (int i : path[l]) S &= ~(1LL << i);
        ret = max(ret, rec(S) + 1);

        return ret;
    }

    int exec() {
        return rec((1LL << V_NUM) - 1);
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    MaximumIndependentSet mis(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        mis.connect(a, b);
    }

    cout << mis.exec() << endl;
    return 0;
}
