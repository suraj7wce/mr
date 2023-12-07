#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void generateKeys(int p, int q, int &n, int &e, int &d) {
    n = p * q;
    int phi = (p - 1) * (q - 1);

    for (e = 2; e < phi; ++e) {
        if (gcd(e, phi) == 1)
            break;
    }

    for (d = 2; d < phi; ++d) {
        if ((d * e) % phi == 1)
            break;
    }
}

int modPow(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int encrypt(char message, int e, int n) {
    return modPow(message, e, n);
}

char decrypt(int encryptedMsg, int d, int n) {
    return modPow(encryptedMsg, d, n);
}

int main() {
    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Generate keys" << endl;
    cout << "2. Encrypt" << endl;
    cout << "3. Decrypt" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int p, q;
        cout << "Enter prime number (p): ";
        cin >> p;
        cout << "Enter another prime number (q): ";
        cin >> q;

        if (!isPrime(p) || !isPrime(q)) {
            cout << "Please enter prime numbers only." << endl;
            return 1;
        }

        int n, e, d;
        generateKeys(p, q, n, e, d);

        cout << "Public Key: {" << e << ", " << n << "}" << endl;
        cout << "Private Key: {" << d << ", " << n << "}" << endl;
    } else if (choice == 2) {
        string message;
        int e, n;
        cout << "Enter the message to encrypt (text): ";
        cin.ignore(); // to clear the newline character from previous input
        getline(cin, message);
        cout << "Enter public key (e): ";
        cin >> e;
        cout << "Enter n: ";
        cin >> n;

        string encryptedMsg = "";
        for (char c : message) {
            int encryptedChar = encrypt(c, e, n);
            encryptedMsg += to_string(encryptedChar) + " ";
        }
        cout << "Encrypted message: " << encryptedMsg << endl;
    } else if (choice == 3) {
        string encryptedMsg;
        int d, n;
        cout << "Enter the encrypted message: ";
        cin.ignore(); // to clear the newline character from previous input
        getline(cin, encryptedMsg);
        cout << "Enter private key (d): ";
        cin >> d;
        cout << "Enter n: ";
        cin >> n;

        stringstream ss(encryptedMsg);
        string token;
        string decryptedMsg = "";
        while (ss >> token) {
            int encryptedChar = stoi(token);
            char decryptedChar = decrypt(encryptedChar, d, n);
            decryptedMsg += decryptedChar;
        }
        cout << "Decrypted message: " << decryptedMsg << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
// 410 52 100 100 89 70 80 325 17 100