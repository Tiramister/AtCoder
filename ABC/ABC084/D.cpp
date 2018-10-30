#include <iostream>
using namespace std;

int main() {
  bool list[100001];
  list[1] = true;
  for (int i = 2; i * i <= 100000; i++) {
    if (!list[i]) {
      for (int j = i + i; j <= 100000; j += i) {
        list[j] = true;
      }
    }
  }

  int number[100001];
  number[1] = 0;
  for (int i = 3; i <= 100000; i += 2) {
    if (!(list[i] || list[(i + 1) / 2])) {
      number[i] = number[i - 2] + 1;
    } else {
      number[i] = number[i - 2];
    }
  }

  int Q, l, r;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    cin >> l >> r;
    cout << number[r] - number[l - 2] << endl;
  }
  return 0;
}
