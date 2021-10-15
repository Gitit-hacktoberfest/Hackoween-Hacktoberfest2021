#include <iostream>
using namespace std;

void shell_sort(int array[], int size)
{
    int i,j,temp;
    for (i = size / 2; i > 0; i = i / 2)
    {
       
        for (j = i; j < size; j++)
        {
            temp = array[j]; 
            int k;
            for(k = j; k >=i && array[k-i]>temp ; k = k - i)
            {     
                array[k] = array[k - i]; 
            }
            array[k]=temp;
        }
    }
}

int main()
{
    int i,  size;
    
    //input array size
    printf("Enter total no. of array elements : ");
    scanf("%d", &size);
   
    int array[size];
    
    //input of the array
    printf("\nEnter the elements of the array: ");    
    for (i =  0 ; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    
    shell_sort(array, size);
    //sorted array output
    printf("\nSorted array: ");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
        
    return 0;
}
