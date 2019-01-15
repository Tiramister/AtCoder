#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

class ModInt {
    using ll = long long;

public:
    int value;
    static int MOD;

    ModInt(ll value = 0) {
        this->value = value % MOD;
        if (this->value < 0) this->value += MOD;
    }

    operator int() const noexcept { return this->value; }

    ModInt& operator=(const ModInt& x) {
        if (this != &x) { this->value = x.value; }
        return *this;
    }

    bool operator==(const ModInt& x) const { return this->value == x.value; }
    bool operator!=(const ModInt& x) const { return !(*this == x); }

    ModInt operator+() const { return value; }
    ModInt operator-() const { return MOD - value; }
    ModInt operator~() const { return (*this) ^ (ModInt(MOD - 2)); }

    ModInt operator++() { return *this += 1; }
    ModInt operator--() { return *this -= 1; }

    ModInt operator++(int) {
        ModInt before = *this;
        ++(*this);
        return before;
    }
    ModInt operator--(int) {
        ModInt before = *this;
        --(*this);
        return before;
    }

    ModInt operator+=(const ModInt& x) { return *this = (this->value + x.value) % MOD; }
    ModInt operator-=(const ModInt& x) { return *this = (this->value + MOD - x.value) % MOD; }
    ModInt operator*=(const ModInt& x) { return *this = ll(this->value) * ll(x.value) % MOD; }
    ModInt operator/=(const ModInt& x) { return *this *= ~ModInt(MOD - 2); }

    ModInt operator^=(const ModInt& x) {
        int n = int(x);
        if (n == 0) return ModInt(1);
        if (n & 1) {
            return (*this) = ((*this) ^ ModInt(n - 1)) * (*this);
        } else {
            return (*this) = ((*this) * (*this)) ^ ModInt(n / 2);
        }
    }

    ModInt operator+(const ModInt& b) const { return ModInt(*this) += b; }
    ModInt operator-(const ModInt& b) const { return ModInt(*this) -= b; }
    ModInt operator*(const ModInt& b) const { return ModInt(*this) *= b; }
    ModInt operator/(const ModInt& b) const { return ModInt(*this) /= b; }
    ModInt operator^(const ModInt& b) const { return ModInt(*this) ^= b; }
};

int ModInt::MOD = 1000000007;

ostream& operator<<(ostream& os, const ModInt& x) { return os << x.value; }
istream& operator>>(istream& is, ModInt& x) { return is >> x.value; }


const int dx[2] = {0, 1}, dy[2] = {1, 0};

ModInt pat[1001][1001];
bool visited[1001][1001];

int main() {
    int H, W;
    cin >> H >> W;

    string S[H];
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    pat[0][0] = 1;

    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));

    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || H <= nx || ny < 0 || W <= ny || S[nx][ny] == '#') continue;

            que.push(make_pair(nx, ny));
            pat[nx][ny] += pat[x][y];
        }
    }

    cout << pat[H - 1][W - 1] << endl;
    return 0;
}
