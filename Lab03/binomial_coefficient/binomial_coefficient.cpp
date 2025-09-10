#include <iostream>

using namespace std;

int coefficient(int, int);

int main() {

	int n = 10, k = 5;
	cout << "The binary coefficient (" << n << ", " << k << ") is " << coefficient(n, k) << endl;

	return 0;
}

int coefficient(int n, int k){
	if (k == 0 || n == k) {
		return 1;
	} else if (n < 0 || k < 0 || k > n) {
		return 0;
	} else {
		return (coefficient(n-1, k-1)) + (coefficient(n-1, k));
	}
}
