#include <bits/stdc++.h>
using namespace std;

int euclid_gcd(int r1, int r2)
{
    if (r2 == 0)
    {
        return r1;
    }

    int q = r1 / r2;
    int r = r1 % r2;

    cout << q << "  " << r1 << "  " << r2 << "  " << r << endl;

    return euclid_gcd(r2, r);
}

int main()
{
    int num1, num2;
    cout << "\n Enter 1st number : ";
    cin >> num1;

    cout << "\n Enter 2nd number : ";
    cin >> num2;

    cout<<endl<< "q  r1  r2  r" << endl;
    int gcd = euclid_gcd(num1, num2);
    cout <<endl<< "GCD: " << gcd << endl;
    return 0;
}