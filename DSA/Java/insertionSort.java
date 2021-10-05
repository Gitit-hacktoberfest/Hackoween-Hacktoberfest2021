/* Insertion Sort: It is a stable and an in-place algorithm.
It works by comparing an always sorted sub array to the remaining elements of the given array
one at a time.*/

/*Time Complexities
Worst and Average case: O(n squared)
Best Case: O(n)*/

// Space Complexity : O(1)

import java.util.Scanner;
public class insertionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];        // array of length n
        for(int j = 0; j<n; j++){     //taking array as user input
            arr[j] = sc.nextInt();
        }

        //insertion sort technique
        //here the sorted sub array at start of the program is the element at index 0.
        for(int firstUnsortedIndex = 1; firstUnsortedIndex < n; firstUnsortedIndex++){
            int newElement = arr[firstUnsortedIndex];

            int i;

            for(i = firstUnsortedIndex; i>0 && arr[i-1]>newElement; i--){
                arr[i] = arr[i-1];
            }

            arr[i] = newElement;
        }

        // printing sorted array
        for(int i = 0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
    }
}
