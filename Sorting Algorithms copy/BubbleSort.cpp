#include <iostream>
#include <vector>
 
using namespace std;
 
void BubbleSort (vector<int> &arr, int n)
{
   for (int i = 0; i < n - 1; ++i)
   { 
      bool swapped = false;
      for (int j = 0; j < n - i - 1; ++j)
      {
         if (arr[j] > arr[j+1]) //check if adjacent element is
                      //not in order
         {
            swap(arr[j], arr[j + 1]);
            swapped = true;
         }
      }
      // Value at n-i-1 will be maximum of all the values below this index.

      if(!swapped)
         break;
   } 
} 
 
int main()
{
   vector<int> arr=[//input array]
   int n = 7;
 
   BubbleSort(arr, n);
 
   // Display the sorted data.
   cout << "\nSorted Data: ";
   for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
   return 0;
}