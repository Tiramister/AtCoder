#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, K, value;

int main()
{
    cin >> N >> K;
    value = 1;
    for (int i = 0; i < N; i++) {
        if (value < K) {
            value *= 2;
        } else {
            value += K;
        }
    }
    cout << value << endl;
    return 0;
}
