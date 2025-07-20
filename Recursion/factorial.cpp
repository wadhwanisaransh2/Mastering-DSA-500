#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive function to print numbers from n to 1
void printDescending(int n) {
    if (n == 0)
        return;
    cout << n << " ";
    printDescending(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "\nNumbers from " << n << " to 1:\n";
    printDescending(n);

    cout << "\n\nFactorial of " << n << " is: " << factorial(n) << endl;

    return 0;
}
