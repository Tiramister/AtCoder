#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t N, a, b;
int M;
vector<vector<size_t>> pass;
int cnt = 0;
vector<bool> used;

void dfs(size_t p)
{
    used[p] = true;
    for (size_t q : pass[p]) {
        if (!used[q]) {
            dfs(q);
        }
    }
}


int main()
{
    cin >> N >> M;
    pass.resize(N);
    used.resize(N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        pass[a - 1].push_back(b - 1);
        pass[b - 1].push_back(a - 1);
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < pass[i].size(); j++) {
            for (size_t k = 0; k < N; k++) {
                used[k] = false;
            }

            size_t r = pass[i].back();
            pass[i].pop_back();

            dfs(0);
            for (size_t p = 0; p < N; p++) {
                if (!used[p]) {
                    cnt++;
                    break;
                }
            }

            pass[i].insert(pass[i].begin(), r);
        }
    }

    cout << cnt << endl;

    return 0;
}
