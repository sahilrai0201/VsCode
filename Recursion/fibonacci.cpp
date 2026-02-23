#include <iostream>
using namespace std;

int fibonacci(int n) {
    // base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    cout << "Fibonacci series up to " << n << " terms is: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
