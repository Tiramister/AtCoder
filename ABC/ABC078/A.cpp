#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define long long ll

char X, Y;

int main()
{
    std::cin >> X >> Y;
    if (X > Y) {
        std::cout << ">";
    } else if (X < Y) {
        std::cout << "<";
    } else {
        std::cout << "=";
    }
    return 0;
}
