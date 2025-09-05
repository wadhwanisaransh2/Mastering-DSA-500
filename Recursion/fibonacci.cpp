#include <iostream>
using namespace std;
int fibonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void printFibonacciSeries(int n) {
    for(int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}
int main() {
    int n = 8;
    cout << "Fibonacci Series up to " << n << " terms:\n";
    printFibonacciSeries(n);
    return 0;
}
