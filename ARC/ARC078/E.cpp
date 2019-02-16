#include <iostream>
#include <string>

using namespace std;
using ll = long long;

// ll N;

bool query(string n) {
    cout << "? " << n << endl;
    char res;
    cin >> res;
    return res == 'Y';

    // bool res = ((stoll(n) <= N) == (n <= to_string(N)));
    // cerr << "NY"[res] << endl;
    // return res;
}

void answer(string n) {
    cout << "! " << n << endl;
}

int main() {
    // cin >> N;

    string ten = "1" + string(10, '0');
    if (query(ten)) {
        // 解は10^k
        ten[0] = '2';
        ten.pop_back();
        while (!ten.empty()) {
            if (!query(ten)) break;
            ten.pop_back();
        }

        if (ten.empty()) {
            answer("1");
        } else {
            ten.push_back('0');
            ten[0] = '1';
            answer(ten);
        }
        return 0;
    }

    ten.pop_back();
    while (!ten.empty()) {
        if (query(ten)) break;
        ten.pop_back();
    }

    //　答えはk桁
    int k = ten.length();
    string ans = "";
    for (int i = 0; i < k - 1; ++i) {
        // 上からi桁目を二分探索
        int ok = 0, ng = 10;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (query(ans + char('0' + mid))) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        ans.push_back(ok + '0');
    }

    // 最後の1桁を求める
    for (int i = 0; i < 10; ++i) {
        // 1桁のときは例外
        if (i == 0 && k == 1) continue;

        if (query(ans + char(i + '0') + '0')) {
            ans.push_back(i + '0');
            break;
        }
    }

    answer(ans);
    return 0;
}
