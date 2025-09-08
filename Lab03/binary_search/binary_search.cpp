#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> &v, int low, int high, int target);

int main () {
	vector<int> list = { 5, 24, 25, 47, 48, 59, 62, 63, 67, 92 };

	int target = 48;

	if (binarySearch(list, 0, list.size() - 1, target)) {
		cout << target << " found." << endl;
	} else {
		cout << target << " not found." << endl;
	}

	return 0;
}

bool binarySearch(vector<int> &v, int low, int high, int target) {
	// Range invalid - Base Case 1
	if (low > high) { return false; }

	// Finding mid-point
	int mid = low + (high - low) / 2;

	if (v[mid] == target) {
		return true; // If middle element is target - Base Case 2
	} else if (v[mid] > target) {
		return binarySearch(v, low, mid - 1, target);
	} else if (v[mid] < target) {
		return binarySearch(v, mid + 1, high, target);
	}

	return false;
}

