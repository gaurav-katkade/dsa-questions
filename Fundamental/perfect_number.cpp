#include <iostream>
using namespace std;

bool isPerfectNumber(int n) {
    if (n <= 1) return false; // Perfect numbers are greater than 1

    int sum = 1; // Start with 1 as it's a divisor of all numbers
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i; // Add the divisor
            if (i != n / i) sum += n / i; // Add the corresponding divisor if it's not the same
        }
    }
    return sum == n;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPerfectNumber(num)) {
        cout << num << " is a perfect number." << endl;
    } else {
        cout << num << " is not a perfect number." << endl;
    }

    return 0;
}
