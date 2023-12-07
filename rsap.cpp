// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// bool is_prime(int num) {
//     if (num < 2) return false;
//     if (num == 2) return true;
//     if (num % 2 == 0) return false;

//     for (int i = 3; i <= sqrt(num); i += 2) {
//         if (num % i == 0) return false;
//     }

//     return true;
// }

// void add_prime_factor(int factor, vector<int>& factors) {
//     if (is_prime(factor)) {
//         factors.push_back(factor);
//     }
// }

// vector<int> prime_factorization(int n) {
//     vector<int> factors;

//     while (n % 2 == 0) {
//         add_prime_factor(2, factors);
//         n = n / 2;
//     }

//     for (int i = 3; i * i <= n; i += 2) {
//         while (n % i == 0) {
//             add_prime_factor(i, factors);
//             n = n / i;
//         }
//     }

//     if (n > 2) {
//         add_prime_factor(n, factors);
//     }

//     return factors;
// }

// int main() {
//     int num; 
//     cout << endl<< "Enter the semiprime number to factorize: ";
//     cin >> num;

//     vector<int> factors = prime_factorization(num);

//     if (factors.size() == 2) {
//         cout <<endl<< num << " is a semiprime." << endl;
//         cout<<endl<<"prime factors: "<<factors[0]<<" "<<factors[1];
//     } else {
//         cout << endl<< num << " is not a semiprime." << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(long long num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (long long i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

void add_prime_factor(long long factor, vector<long long>& factors) {
    if (is_prime(factor)) {
        factors.push_back(factor);
    }
}

vector<long long> prime_factorization(long long n) {
    vector<long long> factors;

    while (n % 2 == 0) {
        add_prime_factor(2, factors);
        n = n / 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            add_prime_factor(i, factors);
            n = n / i;
        }
    }

    if (n > 2) {
        add_prime_factor(n, factors);
    }

    return factors;
}

int main() {
    long long num; 
    cout << endl << "Enter the semiprime number to factorize: ";
    cin >> num;

    vector<long long> factors = prime_factorization(num);

    if (factors.size() == 2) {
        cout << endl << num << " is a semiprime." << endl;
        cout << endl << "prime factors: " << factors[0] << " " << factors[1];
    } else {
        cout << endl << num << " is not a semiprime." << endl;
    }

    return 0;
}

// 1234567890123456789LL
