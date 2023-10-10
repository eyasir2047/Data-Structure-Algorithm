
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickselect(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);
    int pivotRank = pivotIndex - low + 1;

    if (k == pivotRank) {
        return arr[pivotIndex];
    } else if (k < pivotRank) {
        return quickselect(arr, low, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, high, k - pivotRank);
    }
}

double findMedian(vector<int>& arr) {
    int n = arr.size();
    if (n % 2 == 1) {
        // If the number of elements is odd, return the middle element.
        return static_cast<double>(quickselect(arr, 0, n - 1, n / 2 + 1));
    } else {
        // If the number of elements is even, return the average of the two middle elements.
        int mid1 = quickselect(arr, 0, n - 1, n / 2);
        int mid2 = quickselect(arr, 0, n - 1, n / 2 + 1);
        return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2.0;
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
 
    double median = findMedian(arr);

    vector<int> arr2 = {7, 2, 10, 4, 8, 6};
    double median2 = findMedian(arr2);
    cout << "Median is: " << median << endl;
     cout << "Median is: " << median2 << endl;
    return 0;
}

