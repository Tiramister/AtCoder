#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;
int N;
int card[6];

void big_loop(int n);
void swap_loop(int n);

int main()
{
    cin >> N;
    N %= 30;
    big_loop(N / 5);
    swap_loop(N % 5);

    for (int i = 0; i < 6; i++) {
        cout << card[i];
    }
    cout << endl;
    return 0;
}

void big_loop(int n)
{
    int times = 6 - n;
    for (int i = 0; i < times; i++) {
        card[i] = i + n + 1;
    }
    for (int i = 0; i < n; i++) {
        card[i + times] = i + 1;
    }
}

void swap_loop(int n)
{
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        swap(card[i], card[i + 1]);
    }
}
