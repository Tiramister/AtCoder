#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

size_t N;
int M;
vector<int> pass1, passN;

int main()
{
    cin >> N >> M;

    int a, b;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (a == 1) {
            pass1.push_back(b);
        } else if (b == N) {
            passN.push_back(a);
        }
    }

    sort(pass1.begin(), pass1.end());
    sort(passN.begin(), passN.end());

    size_t p1, pN;
    p1 = pN = 0;

    while (p1 < pass1.size() && pN < passN.size()) {
        if (pass1[p1] == passN[pN]) {
            cout << "POSSIBLE" << endl;
            return 0;
        } else if (pass1[p1] < passN[pN]) {
            p1++;
        } else {
            pN++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
