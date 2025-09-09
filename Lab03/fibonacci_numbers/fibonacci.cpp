#include <iostream>

using namespace std;

int fibonacci(int);

int main() {
	
	int n;

	cout << "Please enter the number of fibonacci numbers to generate: ";
	cin >> n;

	cout << "Computing the first " << n << " fibonacci numbers:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << fibonacci(i) << " " << endl;
	}
	
	return 0;
}

int fibonacci(int n) {
	if (n <= 1)
		return n;
	return fibonacci(n -1) + fibonacci(n - 2);
}
