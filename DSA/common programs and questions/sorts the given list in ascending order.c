#include <stdio.h>
int part(int a[], int begn, int n)
{
    int p = a[n];
    int i = (begn - 1);

    for (int j = begn; j <= n - 1; j++)
    {
        if (a[j] <= p)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int tem = a[i + 1];
    a[i + 1] = a[n];
    a[n] = tem;
    return (i + 1);
}

void quicksort(int a[], int begn, int n)
{
    if (begn < n)
    {
        int temp;
        temp = part(a, begn, n);
        quicksort(a, begn, temp - 1);
        quicksort(a, temp + 1, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
/*Time complexity : O(n*logn)
 Space complexity : O(n)*/
