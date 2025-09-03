#include <iostream>

using namespace std;

int AddUp(int arr[], int n);

int main(int argc, char *argv[]) {
	int numbers = (argc - 1);

	int A[10];

	if (numbers > 10) {
		cout << "No more than 10 integers, please." << endl;
		return 1;
	} else {
		for (int i = 1; i < argc; i++)
		{
			A[i -1] = atoi(argv[i]);
		}
		cout << AddUp(A, numbers) << endl;
	}
	


	
	return 0;
}

int AddUp(int arr[], int n) {
	int sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];	
	}
	
	return sum;
}
