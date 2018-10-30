#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    if (N == 26) {
        string ans = "A";
        for (int i = 1; i < N; ++i) {
            char c = 'A' + i;

            // i <= mid <=> ans[i] < c
            int ok = -1, ng = ans.size();
            while (ng - ok > 1) {
                int mid = (ok + ng) / 2;
                cout << "? " << c << " " << ans[mid] << endl;
                char res;
                cin >> res;
                if (res == '>') {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }

            ans.insert(ans.begin() + ng, c);
        }
        cout << "! " << ans << endl;
    } else {
        int path[5][5];
        fill(path[0], path[4] + 5, 0);

        while (true) {
            int p[5][5];
            fill(p[0], p[4] + 5, 0);

            int perm[5];
            for (int i = 0; i < 5; ++i) {
                perm[i] = i;
            }

            do {
                bool right = true;
                for (int i = 0; i < 4; ++i) {
                    for (int j = i + 1; j < 5; ++j) {
                        if (path[perm[i]][perm[j]] < 0) right = false;
                    }
                }

                if (!right) continue;
                for (int i = 0; i < 4; ++i) {
                    for (int j = i + 1; j < 5; ++j) {
                        ++p[perm[i]][perm[j]];
                        ++p[perm[j]][perm[i]];
                    }
                }
            } while (next_permutation(perm, perm + 5));

            int bx = 0, by = 0;
            for (int i = 0; i < 4; ++i) {
                for (int j = i + 1; j < 5; ++j) {
                    if (p[i][j] > p[bx][bx]) {
                        bx = i;
                        by = j;
                    }
                }
            }

            if (bx == 0 && by == 0) {
            }

            cout << "? " << 'A' + bx << " " << 'A' + by << endl;
            char res;
            cin >> res;
            if (res == '<') {
                path[bx][by] = 1;
                path[by][bx] = -1;
            } else {
                path[bx][by] = -1;
                path[by][bx] = 1;
            }
        }
    }
    return 0;
}
