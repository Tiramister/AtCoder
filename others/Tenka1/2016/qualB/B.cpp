#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    set<int> change;
    for (int q = 0; q < 1000; ++q) {
        int cnt = 0;
        for (char c : S) {
            cnt += (c == '(' ? 1 : -1);
            if (cnt < 0) break;
        }

        if (cnt < 0) {
            for (int i = 0; i < N; ++i) {
                if (S[i] == ')') {
                    S[i] = '(';
                    change.insert(i);
                    break;
                }
            }
        } else if (cnt > 0) {
            cnt = 0;
            int front = -1;
            for (int i = 0; i < N; ++i) {
                cnt += (S[i] == '(' ? 1 : -1);
                if (cnt == 0) {
                    front = i;
                }
            }

            cnt = 0;
            int idx = -1;
            for (int i = front + 1; i < N; ++i) {
                cnt += (S[i] == '(' ? 1 : -1);
                if (idx < 0 && S[i] == '(' && cnt > 1) idx = i;
                if (cnt <= 1) idx = -1;
            }
            change.insert(idx);
            S[idx] = ')';
        } else {
            break;
        }
    }

    if (change.empty()) {
        cout << 0 << endl;
    } else {
        cout << change.size() + *change.rbegin() << endl;
    }
    return 0;
}
