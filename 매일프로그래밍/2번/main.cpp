#include <iostream>
using namespace std;
static int *fibonacci_array;

int Fibonacci(int n) {
	if (n == 0) {
		return fibonacci_array[0];
	}
	else if (n == 1)
		return fibonacci_array[1];
	else {
		fibonacci_array[n] = fibonacci_array[n - 1] + fibonacci_array[n - 2];
		return fibonacci_array[n];
	}
}

int main() {

	int n;
	cin >> n;
	fibonacci_array = new int[n];
	fibonacci_array[0] = 1;
	fibonacci_array[1] = 2;

	for (int i = 0; i < n; i++) {
		Fibonacci(i);
	}
	int sum = 0;
	for (int i = 0; fibonacci_array[i] < n; i++) {
		if (fibonacci_array[i] % 2 == 0) {
			sum += fibonacci_array[i];
		}
	}
	cout << sum << endl;

	return 0;
}