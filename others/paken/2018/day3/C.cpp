#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int B;
    cin >> B;

    vector<int> path[B + 1];

    for (int a = 2; a < B; ++a) {
        int b = floor(a * 1.5);
        if (b <= B) {
            path[b].push_back(a);
        }
    }

    int ans = 0;

    bool visited[B];
    fill(visited, visited + B, false);
    queue<int> que;
    que.push(B);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int sv : path[v]) {
            if (visited[sv]) continue;
            visited[sv] = true;
            ++ans;
            que.push(sv);
        }
    }

    cout << ans << endl;
    return 0;
}
