#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int A;
int cnt5 = 0;
int cnt7 = 0;

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> A;
    switch (A) {
    case 5:
      cnt5++;
      break;
    case 7:
      cnt7++;
      break;
    }
  }
  cout << (cnt5 == 2 && cnt7 == 1 ? "YES" : "NO") << endl;
  return 0;
}
