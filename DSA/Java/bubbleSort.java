/* Time Complexity of Bubble Sort Algorithm is O(n squared) */


class BubbleSort {
    void bubbleSort(int arr[]){
        int n = arr.length;   // Substituting to the length because maximum n times function will run.
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {     // Repeatedly swapping the adjacent elements if they are in wrong order
                    int temp = arr[j];         // swap arr[j+1] and arr[j]
                    arr[j] = arr[j + 1];       // swap arr[j+1] and arr[j]
                    arr[j + 1] = temp;         // swap arr[j+1] and arr[j]
                }
            }
        }
    }

    void printArray(int arr[]){   // Function to print array
        int n = arr.length;
        for (int i=0; i<n; ++i) {   // For loops runs over the length of array
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String args[])
    {
        BubbleSort ob = new BubbleSort();
        int arr[] = {44, 84, 75, 22, 62, 10, 56};
        ob.bubbleSort(arr);
        System.out.println("Sorted array");
        ob.printArray(arr);
    }
}
