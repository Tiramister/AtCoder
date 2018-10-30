#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    if (K % 2 == 0) {
        // こっちは簡単
        // K / 2に降りて、後は左の子を辿り続ける
        cout << K / 2 << " ";
        for (int i = 0; i < N - 1; ++i) {
            cout << K << " ";
        }
        cout << endl;
    } else {
        vector<int> ans(N, (K + 1) / 2);

        // N / 2だけ手前にずらす
        for (int i = 0; i < N / 2; ++i) {
            if (ans.back() == 1) {
                ans.pop_back();
            } else {
                --ans.back();
                while (ans.size() < N) {
                    ans.push_back(K);
                }
            }
        }

        for (int v : ans) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
