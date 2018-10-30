#include <bitset>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    bitset<10010> dp = 1;
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        dp |= (dp << p);
    }

    cout << dp.count() << endl;
    return 0;
}
