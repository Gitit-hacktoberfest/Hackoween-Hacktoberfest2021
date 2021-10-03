// Cyclic Sort in JAVA
// Import Package in case you used IDE 

/* What is Cyclic Sort and When to use it : If the given array to be sorted is from [ 1 to N ] or [0 to N ] 
where N is the total elements of the array , Then we can perform cyclic sort. 
For example arr = { 5,4,1,2,3 } Since arr is unsorted array and starts from numbers 1 to 5 the
we can perform Cyclic sort to sort the array.

Time Complexity :
Here N = No.of.elements present in the array.
Best case : If the array is already sorted , then we will have N number of comparisons.
there fore Best case is O(N).
Worst Case : It will be O(N) again. Lets see worst case example arr={3,5,2,1,4} here we wil
make 4 swaps + 5 swaps which is (n-1)+(n) = 2n-1 it will be O(N).  

Space Complexity :
Since we dont have any extra variable or array time complexity will be constant.
therefore it will be O(1) */


// Code Starts

import java.util.Arrays;
import java.util.Scanner;

public class CyclicSort {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Limit: ");
        int l=in.nextInt();
        int[] arr=new int[l];
        for(int i=0;i<l;i++){
            arr[i]=in.nextInt();
        }
        sort(arr);
        System.out.println(Arrays.toString(arr));

    }
    static void sort(int[] arr){
        int i=0;
        while(i<arr.length){
            int correct=arr[i]-1;
            if(arr[i]!=arr[correct]){
                swap(arr,i,correct);
            }else{
                i++;
            }
        }

    }
    static void swap(int[] arr,int first, int second){
        int temp=arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}
