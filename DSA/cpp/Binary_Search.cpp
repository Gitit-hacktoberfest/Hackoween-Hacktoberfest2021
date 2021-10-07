/* Binary Search Algorithm

Time Complexity:
The time complexity of the binary search algorithm is O(log n). The best-case time complexity would be O(1) when the central index would directly match the desired value. The worst-case scenario could be the values at either extremity of the list or values not in the list.

Space Complexity:
The space complexity of the binary search algorithm depends on the implementation of the algorithm. There are two ways of implementing it:
Iterative method - the space complexity would be O(1).
Recursive method - the space complexity would be O(log n).
*/

// Iterative Method -

#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {

    // Repeat until the pointers low and high meet each other
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int x = 4;
    int n = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        cout << "Not found";
    else
        cout << "Element is found at index " << result;
}

// Recursive Method

#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If found at mid, then return it
        if (array[mid] == x)
            return mid;

        // Search the left half
        if (array[mid] > x)
            return binarySearch(array, x, low, mid - 1);

        // Search the right half
        return binarySearch(array, x, mid + 1, high);
    }

    return -1;
}

int main() {
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int x = 4;
    int n = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        cout << "Not found";
    else
        cout << "Element is found at index " << result;
}