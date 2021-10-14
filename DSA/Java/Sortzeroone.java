import java.util.*;
public class Sortzeroone {
    public static void sortzeroone(int arr[])
    {
        //same like patitioning ques that we have done earlier 
        //we would divide into regions 
        // i to end unknown 
        // 0 to j-1 gives region of zeros
        // j to i-1 would give region of ones
        //Its complexity is O(n) and not O(n^2) by using this simple approach
        int i = 0 , j = 0; 
        while(i < arr.length)
        {
            if(arr[i] == 1)
            {
                i++ ;
            }
            else if(arr[i] == 0)
            {
                swap(arr,i,j);
                i++;
                j++;
            }
        }
    }
    public static void swap(int arr[] , int i , int j)
    {
        int temp = arr[i] ;
        arr[i] = arr[j];
        arr[j] = temp ;
    }
    public static void print(int arr[])
    {
        for(int i = 0 ; i < arr.length ;i++)
        {
            System.out.println(arr[i]);
        }
    }
    public static void main(String args[])
    {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i =0 ;i < arr.length ; i++)
        {
            arr[i] = scn.nextInt();
        }
        sortzeroone(arr);
        print(arr);
    }
}
