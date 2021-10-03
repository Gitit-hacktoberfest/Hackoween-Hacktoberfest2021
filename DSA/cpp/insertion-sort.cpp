#include<iostream>
using namespace std;
//display function to display the array
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
//insertionSort function to sort the array
void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   //insert in right place
   }
}
//main function
int main() {
   int n;
   cout << "Enter the number of elements(number should be less than or equal to 100): ";
   cin >> n;
   int arr[100];    //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   insertionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}