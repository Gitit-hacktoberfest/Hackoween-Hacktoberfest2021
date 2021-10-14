import java.util.*;
//its complexity is O(n^2) i have explained how this algo is working in the output after  you run this
public class Selectionsort {
    public static void selectionsort(int arr[])
    {
        for(int i =0 ; i < arr.length -1 ; i++)
        {
            int min = i ;
            for(int j = i+1; j < arr.length ; j++)
            {
                if(isSmaller(arr,j,min))
                {
                    min = j; 
                }
            }
            swap(arr,i,min);
        }
    }
    public static boolean isSmaller(int arr[] , int i , int j)
    {
        System.out.println("Comparing " + arr[i] + " and " + arr[j]);
        if(arr[i] < arr[j])
        {
            return true ;
        }
        else 
        {
            return false ;
        }
    }
    public static void swap(int arr[] , int i , int j)
    {
        System.out.println("Swapping " + arr[i] + " and " + arr[j]);
        int temp = arr[i] ;
        arr[i] = arr[j] ;
        arr[j] = temp ;
    }
    public static void print(int arr[])
    {
        for(int i =0 ; i < arr.length ; i++)
        {
            System.out.println(arr[i]);
        }
    }
    public static void main(String args[]) throws Exception 
    {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        int n = scn.nextInt();
        int arr[] = new int[n];
        for(int i = 0 ; i < arr.length ; i++)
        {
            arr[i] = scn.nextInt();
        }
        selectionsort(arr);
        print(arr);
    }
}
