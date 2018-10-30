#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int size[N];

    for (int i = 0; i < N; i++) {
        cin >> size[i];
    }

    int counter = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (size[j] == size[i]) {
                counter--;
                break;
            }
        }
        counter++;
    }
    cout << counter;
    return 0;
}
