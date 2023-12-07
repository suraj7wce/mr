#include<iostream>
#include<vector>

using namespace std;

long long find_multiplicative_inverse(long long a, long long b) {
    long long t1 = 0, t2 = 1, q, r, t;
    long long main_a = a;

    while (b > 0) {
        q = a / b;
        r = a % b;
        t = t1 - t2 * q;

        a = b;
        b = r;
        t1 = t2;
        t2 = t;
    }

    if (t1 < 0) {
        t1 += main_a;
    }

    return t1;
}

int main() {
    int count;
    cout << "Enter the number of equations: ";
    cin >> count;

    vector<int> a(count), m(count);

    for (int i = 0; i < count; i++) {
        cout << "Equation No " << i + 1 << ":\n";
        cout << "a = ";
        cin >> a[i];
        cout << "m = ";
        cin >> m[i];
    }

    long long M = 1;
    for (int i = 0; i < count; i++) {
        M *= m[i];
    }

    vector<long long> M_vector(count), M_inverse_vector(count);

    for (int i = 0; i < count; i++) {
        M_vector[i] = M / m[i];
        M_inverse_vector[i] = find_multiplicative_inverse(m[i], M_vector[i]);
    }

    long long X = 0;
    for (int i = 0; i < count; i++) {
        X += (a[i] * M_vector[i] * M_inverse_vector[i]);
    }

    X %= M;

    cout << "\nM: " << M << "\n";
     cout << "Mi: ";
    for (int i = 0; i < count; i++) {
        cout << M_vector[i] << " ";
    }
    cout << "\nM^-1: ";
    for (int i = 0; i < count; i++) {
        cout << M_inverse_vector[i] << " ";
    }
    cout << "\n";
    cout << "Value of X: " << X << "\n";
   

    return 0;
}
