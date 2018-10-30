#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N;

int main()
{
    cin >> N;
    if ((N % 1000) % 111 == 0 || (N / 10) % 111 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
