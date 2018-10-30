#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long int INF = 1000000001;

int main() {
    int N;
    cin >> N;
    int n[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }
    n[N] = INF;

    sort(n, n + N + 1);

    int pre = 0;
    int ctr = 0;
    int red = 0;

    for (int i = 0; i < N + 1; i++) {
        if (n[i] > pre) {
            if (ctr >= pre) {
                red += ctr - pre;
            } else {
                red += ctr;
            }
            pre = n[i];
            ctr = 1;
        } else {
            ctr++;
        }
    }
    cout << red;
    return 0;
}
