#include <iostream>

using namespace std;

int main() {
    int cnt[4];
    fill(cnt, cnt + 4, 0);
    for (int i = 0; i < 6; ++i) {
        int a;
        cin >> a;
        ++cnt[--a];
    }

    int p = 0;
    for (int i = 0; i < 4; ++i) p += cnt[i] % 2;
    cout << (p <= 2 ? "YES" : "NO") << endl;
    return 0;
}
