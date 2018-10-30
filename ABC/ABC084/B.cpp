#include <iostream>
#include <string>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  string letter;
  cin >> letter;

  for (int i = 0; i < A + B + 1; i++) {
    if (i == A) {
      if (letter[i] != '-') {
        cout << "No";
        return 0;
      }
    } else {
      if (letter[i] == '-') {
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
  return 0;
}
