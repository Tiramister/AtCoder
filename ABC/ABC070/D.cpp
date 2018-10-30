#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

template <typename T>
class Queue {
private:
    vector<T> pulled, pushed;

public:
    void push(T a) {
        pushed.push_back(a);
    }

    T pop() {
        if (pulled.empty()) {
            reverse(pushed.begin(), pushed.end());
            pulled = pushed;
            pushed.clear();
        }
        T top = pulled.back();
        pulled.pop_back();
        return top;
    }

    T front() {
        return pulled.front();
    }

    int size() {
        return pulled.size() + pushed.size();
    }

    bool empty() {
        return size() == 0;
    }
};


int main() {
    int N;
    cin >> N;

    vector<pair<int, ll>> path[N + 1];
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        path[a].push_back(make_pair(b, c));
        path[b].push_back(make_pair(a, c));
    }

    int Q, K;
    cin >> Q >> K;

    ll d[N + 1];
    fill(d, d + N + 1, -1);
    d[K] = 0;

    Queue<int> que;
    que.push(K);

    while (!que.empty()) {
        int v = que.pop();
        for (auto p : path[v]) {
            int sv;
            ll c;
            tie(sv, c) = p;

            if (d[sv] < 0) {
                d[sv] = d[v] + c;
                que.push(sv);
            }
        }
    }

    for (int q = 0; q < Q; ++q) {
        int x, y;
        cin >> x >> y;
        cout << d[x] + d[y] << endl;
    }
    return 0;
}
