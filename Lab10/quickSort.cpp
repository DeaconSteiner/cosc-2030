#include <iostream>
#include <utility>
#include <vector>

void quickSort(std::vector<int>&, int, int);
int partition(std::vector<int>&, int, int);

int main() {
    std::vector<int> to_sort = {5, 2, 8, 3, 1};

    std::cout << "The unsorted array: ";
    for (int num : to_sort) std::cout << num << " ";
    std::cout << std::endl;

    quickSort(to_sort, 0, to_sort.size()-1);

    std::cout << "The sorted array: ";
    for (int num : to_sort) std::cout << num << " ";
    std::cout << std::endl;
}

void quickSort(std::vector<int> &rArr, int low, int high) {
    if (low < high) {
        int q = partition(rArr, low, high);
        quickSort(rArr, low, q-1);
        quickSort(rArr, q+1, high);
    }
}

int partition(std::vector<int> &rArr, int low, int high) {
    int x = rArr.at(high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (rArr.at(j) <= x) {
            i = i + 1;
            std::swap(rArr.at(i), rArr.at(j));
        }
    }

    std::swap(rArr.at(i+1), rArr.at(high));

    return i+1;
}
