#include <iostream>

using namespace std;

int factorial(int);

int main() {
	
	int target;

	cout << "Enter a non-negative integer: ";
	cin >> target;

	int result = factorial(target);
	if (result == -1) {
		return 1;
	}
	cout << target << "! is " << result << endl;
	
	return 0;
}

int factorial(int arg) {
	
	if (arg < 0) {
		cout << "ERROR: Negative input not allowed." << endl;
		return -1;
	} else if (arg == 0) {
		return 1;
	} else {
		return arg * factorial(arg - 1);
	}
}
