#include <iostream>

int extendedEuclid(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedEuclid(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedEuclid(a, m, x, y);
    if (gcd != 1) {
        // Inverse doesn't exist
        return -1;
    } else {
        return (x % m + m) % m;
    }
}

int main() {
    const int MOD = 100;

    std::cout << "Multiplicative inverses modulo 100:\n";
    for (int i = 1; i < MOD; ++i) {
        int inverse = modInverse(i, MOD);
        std::cout << "Inverse of " << i << " is: " << inverse << "\n";
    }

    return 0;
}
